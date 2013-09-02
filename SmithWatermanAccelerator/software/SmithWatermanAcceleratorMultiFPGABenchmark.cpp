/*  File Name        : SmithWatermanAccelerator.cpp
 *  Description      : Tests the Smith Waterman Accelerator with a small "reference sequence"
 *                     and a few small "query sequences".
 *
 *  Revision History :
 *      Albert Ng   Aug 08 2013     Initial Revision 
 *      Albert Ng   Aug 22 2013     Changed sequence computation to unsigned char
 */

#include <stdio.h>
#include <string.h>
#include <picodrv.h>
#include <pico_errors.h>
#include <pthread.h>
#include <fstream>
#include <iostream>
#include <time.h>

#define EOQ 0xFFFFFFFF
#define RESULT_BUF_SIZE 128

struct write_thread_args {
    PicoDrv* pico;
    int      stream;
    int      num_queries;
    int      query_len_bytes; // in bytes
    char *   query_buf;
    int      ref_len_bytes;   // in bytes
    uint32_t cell_score_threshold;
    int      engine_id;
    uint32_t ref_addr;
};

struct read_thread_args {
    PicoDrv*   pico;
    int        stream;
    uint32_t * results_buf;
    int        num_queries;
    int        engine_id;
};

void* stream_write_thread(void* args) {
    PicoDrv *pico = ((write_thread_args*)args)->pico;
    int stream = ((write_thread_args*)args)->stream;
    int num_queries = ((write_thread_args*)args)->num_queries;
    int query_len_bytes = ((write_thread_args*)args)->query_len_bytes;
    char* query_buf = ((write_thread_args*)args)->query_buf;
    int ref_len_bytes = ((write_thread_args*)args)->ref_len_bytes;
    uint32_t cell_score_threshold = ((write_thread_args*)args)->cell_score_threshold;
    int engine_id = ((write_thread_args*)args)->engine_id;
    uint32_t ref_addr = ((write_thread_args*)args)->ref_addr;

    uint32_t out_buf[1024];
    // For each query
    for (int i = 0; i < 1; i++) {
//        printf("Engine %i, Ref addr %i\n", engine_id, ref_addr);
        out_buf[0] = ref_len_bytes/32;
        out_buf[1] = ref_addr;
        out_buf[2] = (engine_id << 16) + (query_len_bytes * 4);
        //out_buf[2] = (engine_id << 16) + (query_len_bytes * 4)/64;
        out_buf[3] = cell_score_threshold;
        // For each query block of the query
        for (int j = 0; j < (query_len_bytes * 4)/64; j++) {
            // For each 32-bit chunk of the 128-bit query block
            for (int k = 0; k < 4; k++) {
                out_buf[j*4 + k + 4] = ((unsigned char) query_buf[j*16 + k*4]) +
                                       ((unsigned char) query_buf[j*16 + k*4 + 1] << 8) +
                                       ((unsigned char) query_buf[j*16 + k*4 + 2] << 16) +
                                       ((unsigned char) query_buf[j*16 + k*4 + 3] << 24);
            }
        }
        pico->WriteStream(stream, out_buf, 16 + query_len_bytes);
    }
}

void* stream_read_thread(void* args) {
    uint32_t buf[1024];
    PicoDrv *pico = ((read_thread_args*)args)->pico;
    int stream = ((read_thread_args*)args)->stream;
    uint32_t * results_buf = ((read_thread_args*)args)->results_buf;
    int num_queries = ((read_thread_args*)args)->num_queries;
    int engine_id = ((read_thread_args*)args)->engine_id;

    int offset = 0;
    uint32_t temp_buf[1024];
    int num_queries_done = 0;
    //while (num_queries_done != num_queries) {
    while (num_queries_done != 1) {
        int num_bytes_available = pico->GetBytesAvailable(stream, true);
        if (num_bytes_available >= 16) {
            int num_bytes_to_read = num_bytes_available > 4096 ? 4096 : (num_bytes_available/16)*16;
            // Read full 128-bit packets
            pico->ReadStream(stream, temp_buf, num_bytes_to_read);

            // For each result location read
            for (int i = 0; i < num_bytes_to_read / 16; i++) {
                results_buf[offset*2] = temp_buf[i*4];
                results_buf[offset*2 + 1] = temp_buf[i*4 + 1];
                if (results_buf[offset*2] == EOQ) {
                    num_queries_done++;
                    offset = 0;
                } else {
                    offset++;
                }
            }
        }
    }
}   

int main(int argc, char* argv[])
{
    int         err, num_engines_per_fpga, num_fpgas;
    int**       stream;
    uint32_t    cell_score_threshold;
    uint32_t***  query_ids;
    char *  ref_buf;
    char * query_buf;
    int        query_len;
    char        ibuf[1024];
    uint32_t ***  results_buf;
    PicoDrv     **pico;
    const char* bitFileName;
    const char* ref_filename;
    int num_queries;
    pthread_t** read_thread;
    pthread_t** write_thread;
    read_thread_args** rta;
    write_thread_args** wta;

    // specify the .bit file name on the command line
    if (argc < 7) {
        fprintf(stderr, "Usage: ./SmithWatermanAcceleratorMultiFPGABenchmark <BIT FILE> <NUM FPGAS> <NUM ENGINES PER FPGA> <CELL SCORE THRESHOLD> <REF SEQ FILE> <QUERY SEQ FILE>\n");
        exit(1);
    }
    bitFileName = argv[1];
    num_fpgas = atoi(argv[2]);
    num_engines_per_fpga = atoi(argv[3]);
    cell_score_threshold = (uint32_t) atoi(argv[4]);
    ref_filename = argv[5];
    num_queries = argc - 6;
    const char* query_filename = argv[6];
    
    printf("Configuration: %i FPGAs, %i Engines per FPGA\n", num_fpgas, num_engines_per_fpga);

    // Read ref seq file into memory
    std::ifstream ref_file;
    std::ifstream::pos_type ref_size;
    ref_file.open(ref_filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (ref_file.is_open()) {
        ref_size = ref_file.tellg();
        ref_buf = new char[ref_size];
        ref_file.seekg(0, std::ios::beg);
        ref_file.read(ref_buf, ref_size);
        ref_file.close();
        printf("Read ref seq file '%s' of length %iB\n", ref_filename, (int) ref_size); 
    } else {
        fprintf(stderr, "Unable to open ref seq file '%s'", ref_filename);
        exit(1);
    }
    
    // Read query seq files into memory
    std::ifstream query_file;
    std::ifstream::pos_type query_size;
    query_file.open(query_filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (query_file.is_open()) {
        query_size = query_file.tellg();
        query_len = (int) query_size;
        query_buf = new char[query_size];
        query_file.seekg(0, std::ios::beg);
        query_file.read(query_buf, query_size);
        query_file.close();
        printf("Read query seq file '%s' of length %iB\n", query_filename, (int) query_size);
    } else {
        fprintf(stderr, "Unable to open query seq file '%s'", query_filename);
        exit(1);
    }

    // Load FPGAs with bitfile
    pico = new PicoDrv*[num_fpgas];
    for (int i = 0; i < num_fpgas; i++) {
        printf("Loading FPGA %i with '%s' ...\n", i, bitFileName);
        err = RunBitFile(bitFileName, &(pico[i]));
        if (err < 0) {
            fprintf(stderr, "RunBitFile error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
            exit(1);
        }
    }

    // Open streams to engines
    printf("Opening streams\n");
    stream = new int*[num_fpgas];
    for (int i = 0; i < num_fpgas; i++) {
        stream[i] = new int[num_engines_per_fpga];
        for (int j = 0; j < num_engines_per_fpga; j++) {
            stream[i][j] = pico[i]->CreateStream(j+1);
            if (stream[i][j] < 0) {
                fprintf(stderr, "couldn't open stream %i on FPGA %i! (return code: %i)\n", j+1, i, stream[i][j]);
                exit(1);
            }
        }
    }
    
    // Write reference sequence to the DRAMs
    printf("Writing ref seq to DRAMs\n");
    for (int i = 0; i < num_fpgas; i++) {
        err = pico[i]->WriteRam(0, ref_buf, ref_size, PICO_DDR3_0);
        if (err < 0) {
            fprintf(stderr, "WriteRam error on FPGA %i: %s\n", i, PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
            exit(1);
        } else if (err != ref_size) {
            fprintf(stderr, "WriteRam on FPGA %i wrote %i bytes instead of the desire %i bytes\n", i, err, (int) ref_size);
            exit(1);
        }
    }
    sleep(1);
  
    // Start read/write threads 
    printf("Starting Smith Waterman tests\n");
    results_buf = new uint32_t** [num_fpgas];
    for (int i = 0; i < num_fpgas; i++) {
        results_buf[i] = new uint32_t* [num_engines_per_fpga];
        for (int j = 0; j < num_engines_per_fpga; j++) {
            results_buf[i][j] = new uint32_t[RESULT_BUF_SIZE];
            for (int k = 0; k < RESULT_BUF_SIZE; k++) {
                results_buf[i][j][k] = 0;
            }
        }
    }
    wta = new write_thread_args* [num_fpgas];
    rta = new read_thread_args* [num_fpgas];
    for (int i = 0; i < num_fpgas; i++) {
        wta[i] = new write_thread_args[num_engines_per_fpga];
        rta[i] = new read_thread_args[num_engines_per_fpga];
        for (int j = 0; j < num_engines_per_fpga; j++) {
            wta[i][j].pico = pico[i];
            wta[i][j].stream = stream[i][j];
            wta[i][j].num_queries = 1;
            wta[i][j].query_len_bytes = query_len;
            wta[i][j].query_buf = query_buf;
            wta[i][j].ref_len_bytes = (1 << 30) / (num_fpgas * num_engines_per_fpga);
            wta[i][j].cell_score_threshold = cell_score_threshold;
            wta[i][j].engine_id = i*num_engines_per_fpga + j;
            //wta[i][j].ref_addr = (i*num_engines_per_fpga + j) * ((1 << 25) / (num_fpgas * num_engines_per_fpga));
            wta[i][j].ref_addr = 0;
            rta[i][j].pico = pico[i];
            rta[i][j].stream = stream[i][j];
            rta[i][j].results_buf = results_buf[i][j];
            rta[i][j].num_queries = 1;
            rta[i][j].engine_id = i*num_engines_per_fpga + j;
        }
    }
    read_thread = new pthread_t*[num_fpgas];
    write_thread = new pthread_t*[num_fpgas];
    printf("ref_len_bytes: %i\n", ((1 << 30) / (num_fpgas * num_engines_per_fpga)));


    // TIMED CODE
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < num_fpgas; i++) {
        read_thread[i] = new pthread_t[num_engines_per_fpga];
        write_thread[i] = new pthread_t[num_engines_per_fpga];
        for (int j = 0; j < num_engines_per_fpga; j++) {
            pthread_create(&(read_thread[i][j]), NULL, &stream_read_thread, (void*) &(rta[i][j]));
            pthread_create(&(write_thread[i][j]), NULL, &stream_write_thread, (void*) &(wta[i][j]));
        }
    }

    // Join read/write threads
    for (int i = 0; i < num_fpgas; i++) {
        for (int j = 0; j < num_engines_per_fpga; j++) {
            pthread_join(read_thread[i][j], NULL);
            pthread_join(write_thread[i][j], NULL);
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    double elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    double numCells = query_len * 4 * 4294967296;
    printf("Computation took %f seconds\n", elapsed);
    printf("Total cells computed (billions): %f\n", numCells/1000000000.0);
    printf("Performance: %f GCUPS\n", numCells/elapsed/1000000000.0);

    // Print results
/*    for (int i = 0; i < num_fpgas; i++) {
        for (int j = 0; j < num_engines_per_fpga; j++) {
            printf("FPGA: %i Engine: %i\n", i, j);
            for (int k = 0; k < RESULT_BUF_SIZE; k++) {
                printf("%i\t", results_buf[i][j][k]);
            }
            printf("\n\n");
        }
    }*/

    // streams are automatically closed when the PicoDrv object is destroyed, or on program termination, but
    //   we can also close a stream manually.
    for (int i = 0; i < num_fpgas; i++) {
        for (int j = 0; j < num_engines_per_fpga; j++) {
            pico[i]->CloseStream(stream[i][j]);
        }
    }
    return 0;
}

