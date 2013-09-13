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

#define EOQ 0xFFFFFFFF
#define RESULT_BUF_SIZE 128

struct write_thread_args {
    PicoDrv* pico;
    int      stream;
    int      num_queries;
    int *    query_len_bytes; // in bytes
    char **  query_buf;
    int      ref_len_bytes;   // in bytes
    uint32_t cell_score_threshold;
    int      engine_id;
    uint32_t* query_ids;
};

struct read_thread_args {
    PicoDrv*   pico;
    int        stream;
    uint32_t * results_buf;
    int        num_queries;
    int        engine_id;
    uint32_t*  query_ids;
};

void* stream_write_thread(void* args) {
    PicoDrv *pico = ((write_thread_args*)args)->pico;
    int stream = ((write_thread_args*)args)->stream;
    int num_queries = ((write_thread_args*)args)->num_queries;
    int* query_len_bytes = ((write_thread_args*)args)->query_len_bytes;
    char** query_buf = ((write_thread_args*)args)->query_buf;
    int ref_len_bytes = ((write_thread_args*)args)->ref_len_bytes;
    uint32_t cell_score_threshold = ((write_thread_args*)args)->cell_score_threshold;
    int engine_id = ((write_thread_args*)args)->engine_id;
    uint32_t* query_ids = ((write_thread_args*)args)->query_ids;

    uint32_t out_buf[1024];
    // For each query
    for (int i = 0; i < num_queries; i++) {
        out_buf[0] = (ref_len_bytes * 4)/128;
        out_buf[1] = 0;
        out_buf[2] = (query_ids[i] << 16) + (query_len_bytes[i] * 4-1);
        out_buf[3] = cell_score_threshold;
        // For each query block of the query
        for (int j = 0; j < (query_len_bytes[i] * 4)/64; j++) {
            // For each 32-bit chunk of the 128-bit query block
            for (int k = 0; k < 4; k++) {
                out_buf[j*4 + k + 4] = ((unsigned char) query_buf[i][j*16 + k*4]) +
                                       ((unsigned char) query_buf[i][j*16 + k*4 + 1] << 8) +
                                       ((unsigned char) query_buf[i][j*16 + k*4 + 2] << 16) +
                                       ((unsigned char) query_buf[i][j*16 + k*4 + 3] << 24);
            }
        }
        fprintf(stderr, "Engine %i, Writing query %i with %i bytes\n", engine_id, query_ids[i], 16+query_len_bytes[i]);
        pico->WriteStream(stream, out_buf, 16 + query_len_bytes[i]);
    }
}

void* stream_read_thread(void* args) {
    uint32_t buf[1024];
    PicoDrv *pico = ((read_thread_args*)args)->pico;
    int stream = ((read_thread_args*)args)->stream;
    uint32_t * results_buf = ((read_thread_args*)args)->results_buf;
    int num_queries = ((read_thread_args*)args)->num_queries;
    int engine_id = ((read_thread_args*)args)->engine_id;
    uint32_t* query_ids = ((read_thread_args*)args)->query_ids;

    int offset = 0;
    uint32_t temp_buf[1024];
    int num_queries_done = 0;
    while (num_queries_done != num_queries) {
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
                }
                offset++;
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
    char **** query_buf;
    int ***       query_len;
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
        fprintf(stderr, "Usage: ./SmithWatermanAccelerator <BIT FILE> <NUM FPGAS> <NUM ENGINES PER FPGA> <CELL SCORE THRESHOLD> <REF SEQ FILE> <QUERY SEQ FILE 1> [<QUERY SEQ FILE 2> ...]");
        exit(1);
    }
    bitFileName = argv[1];
    num_fpgas = atoi(argv[2]);
    num_engines_per_fpga = atoi(argv[3]);
    cell_score_threshold = (uint32_t) atoi(argv[4]);
    ref_filename = argv[5];
    num_queries = argc - 6;
    const char* query_filenames[num_queries];
    for (int i = 0; i < num_queries; i++) {
        query_filenames[i] = argv[i+6];
    }
    
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
    query_buf = new char*** [num_fpgas];
    query_len = new int** [num_fpgas];
    query_ids = new uint32_t** [num_fpgas];
    int num_queries_per_engine[num_fpgas][num_engines_per_fpga];
    for (int i = 0; i < num_fpgas; i++) {
        for (int j = 0; j < num_engines_per_fpga; j++) {
            num_queries_per_engine[i][j] = 0;
        }
    }
    for (int i = 0; i < num_fpgas; i++) {
        query_buf[i] = new char** [num_engines_per_fpga];
        query_len[i] = new int* [num_engines_per_fpga];
        query_ids[i] = new uint32_t* [num_engines_per_fpga];
        for (int j = 0; j < num_engines_per_fpga; j++) {
            query_buf[i][j] = new char* [num_queries_per_engine[i][j]];
            query_len[i][j] = new int [num_queries_per_engine[i][j]];
            query_ids[i][j] = new uint32_t [num_queries_per_engine[i][j]];
        }
    }
    int cur_fpga = 0;
    int cur_engine = 0;
    for (int i = 0; i < num_queries; i++) {
        std::ifstream query_file;
        std::ifstream::pos_type query_size;
        query_file.open(query_filenames[i], std::ios::in | std::ios::binary | std::ios::ate);
        if (query_file.is_open()) {
            query_size = query_file.tellg();
            query_len[cur_fpga][cur_engine][i/(num_fpgas * num_engines_per_fpga)] = (int) query_size;
            query_buf[cur_fpga][cur_engine][i/(num_fpgas * num_engines_per_fpga)] = new char[query_size];
            query_ids[cur_fpga][cur_engine][i/(num_fpgas * num_engines_per_fpga)] = i;
            num_queries_per_engine[cur_fpga][cur_engine]++;
            query_file.seekg(0, std::ios::beg);
            query_file.read(query_buf[cur_fpga][cur_engine][i/(num_fpgas * num_engines_per_fpga)], query_size);
            query_file.close();
            printf("Read query seq file '%s' of length %iB for FPGA %i, engine %i\n", query_filenames[i], (int) query_size, cur_fpga, cur_engine);
            cur_fpga++;
            if (cur_fpga == num_fpgas) {
                cur_engine++;
                cur_engine %= num_engines_per_fpga;
                cur_fpga = 0;
            }
        } else {
            fprintf(stderr, "Unable to open query seq file '%s'", query_filenames[i]);
            exit(1);
        }
    }
    for (int i = 0; i < num_fpgas; i++) {
        for (int j = 0; j < num_engines_per_fpga; j++) {
            printf("FPGA: %i, Engine: %i, Queries: %i\n", i, j, num_queries_per_engine[i][j]);
        }
    }

    // Load FPGAs with bifile
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
            wta[i][j].num_queries = num_queries_per_engine[i][j];
            wta[i][j].query_len_bytes = query_len[i][j];
            wta[i][j].query_buf = query_buf[i][j];
            wta[i][j].ref_len_bytes = (int) ref_size;
            wta[i][j].cell_score_threshold = cell_score_threshold;
            wta[i][j].engine_id = i*num_engines_per_fpga + j;
            wta[i][j].query_ids = query_ids[i][j];
            rta[i][j].pico = pico[i];
            rta[i][j].stream = stream[i][j];
            rta[i][j].results_buf = results_buf[i][j];
            rta[i][j].num_queries = num_queries_per_engine[i][j];
            rta[i][j].engine_id = i*num_engines_per_fpga + j;
            rta[i][j].query_ids = query_ids[i][j];
        }
    }
    read_thread = new pthread_t*[num_fpgas];
    write_thread = new pthread_t*[num_fpgas];
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

    // Print results
    for (int i = 0; i < num_fpgas; i++) {
        for (int j = 0; j < num_engines_per_fpga; j++) {
            printf("FPGA: %i Engine: %i\n", i, j);
            for (int k = 0; k < RESULT_BUF_SIZE; k++) {
                printf("%i\t", results_buf[i][j][k]);
            }
            printf("\n\n");
        }
    }

    // streams are automatically closed when the PicoDrv object is destroyed, or on program termination, but
    //   we can also close a stream manually.
    for (int i = 0; i < num_fpgas; i++) {
        for (int j = 0; j < num_engines_per_fpga; j++) {
            pico[i]->CloseStream(stream[i][j]);
        }
    }
    return 0;
}

