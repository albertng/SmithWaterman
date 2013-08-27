/*  File Name        : SmithWatermanAcceleratorBenchmark.cpp
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
#define ITERATIONS 1000000
struct write_thread_args {
    PicoDrv* pico;
    int      stream;
    int      query_len_bytes; // in bytes
    char *   query_buf;
    int      ref_len_bytes;   // in bytes
    uint32_t cell_score_threshold;
};

struct read_thread_args {
    PicoDrv*   pico;
    int        stream;
    uint32_t * results_buf;
};

void* stream_write_thread(void* args) {
    PicoDrv *pico = ((write_thread_args*)args)->pico;
    int stream = ((write_thread_args*)args)->stream;
    int query_len_bytes = ((write_thread_args*)args)->query_len_bytes;
    char* query_buf = ((write_thread_args*)args)->query_buf;
    int ref_len_bytes = ((write_thread_args*)args)->ref_len_bytes;
    uint32_t cell_score_threshold = ((write_thread_args*)args)->cell_score_threshold;

    uint32_t out_buf[1024];
    // For each query
    //for (int i = 0; i < ITERATIONS; i++) {
    for (int i = 0; i < 1; i++) {
        //out_buf[0] = (ref_len_bytes * 4)/128;
        out_buf[0] = 33554432;
        out_buf[1] = 0;
        out_buf[2] = (i << 16) + (query_len_bytes * 4)/64;
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

    int offset = 0;
    uint32_t temp_buf[1024];
    int num_queries_done = 0;
    //while (num_queries_done != ITERATIONS) {
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
    int         err, stream;
    uint32_t    cell_score_threshold;
    char *  ref_buf;
    char *  query_buf;
    int        query_len;
    char        ibuf[1024];
    uint32_t *  results_buf;
    PicoDrv     *pico;
    const char* bitFileName;
    const char* ref_filename;
    pthread_t read_thread, write_thread;
    int iret1, iret2;
    read_thread_args rta;
    write_thread_args wta;

    // specify the .bit file name on the command line
    if (argc < 5) {
        fprintf(stderr, "Usage: ./SmithWatermanAccelerator <BIT FILE> <CELL SCORE THRESHOLD> <REF SEQ FILE> <QUERY SEQ FILE>");
        exit(1);
    }
    bitFileName = argv[1];
    cell_score_threshold = (uint32_t) atoi(argv[2]);
    ref_filename = argv[3];
    const char* query_filename = argv[4];
    
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
        printf("Read ref seq file of length %iB\n", (int) ref_size); 
    } else {
        fprintf(stderr, "Unable to open ref seq file");
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
        printf("Read query seq file of length %iB\n", (int) query_size);
    } else {
        fprintf(stderr, "Unable to open query seq file");
        exit(1);
    }
    
    // The RunBitFile function will locate a Pico card that can run the given bit file, and is not already
    //   opened in exclusive-access mode by another program. It requests exclusive access to the Pico card
    //   so no other programs will try to reuse the card and interfere with us.
    printf("Loading FPGA with '%s' ...\n", bitFileName);
    err = RunBitFile(bitFileName, &pico);
    if (err < 0) {
        // We use the PicoErrors_FullError function to decipher error codes from RunBitFile.
        // This is more informative than just printing the numeric code, since it can report the name of a
        //   file that wasn't found, for example.
        fprintf(stderr, "RunBitFile error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }
    
    // Open stream to engines
    printf("Opening streams\n");
    stream = pico->CreateStream(1);
    if (stream < 0) {
        fprintf(stderr, "couldn't open stream 1! (return code: %i)\n", stream);
        exit(1);
    }
    
    // Write reference sequence to the DRAM
    printf("Writing ref seq to DRAM\n");
    err = pico->WriteRam(0, ref_buf, ref_size, PICO_DDR3_0);
    if (err < 0) {
        fprintf(stderr, "WriteRam error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    } else if (err != ref_size) {
        fprintf(stderr, "WriteRam wrote %i bytes instead of the desire %i bytes\n", err, (int) ref_size);
        exit(1);
    }
    sleep(1);
  
    // Start read/write threads 
    printf("Starting Smith Waterman tests\n");
    results_buf = new uint32_t[128];
    for (int i = 0; i < 128; i++) {
        results_buf[i] = 0;
    }
    wta.pico = pico;
    wta.stream = stream;
    wta.query_len_bytes = query_len;
    wta.query_buf = query_buf;
    wta.ref_len_bytes = (int) ref_size;
    wta.cell_score_threshold = cell_score_threshold;
    rta.pico = pico;
    rta.stream = stream;
    rta.results_buf = results_buf;

    clock_t begin = clock();
    iret1 = pthread_create(&read_thread, NULL, &stream_read_thread, (void*) &rta);
    iret2 = pthread_create(&write_thread, NULL, &stream_write_thread, (void*) &wta);
    pthread_join(read_thread, NULL);
    pthread_join(write_thread, NULL);
    clock_t end = clock();
    double timeSec = (end - begin) / ((double) CLOCKS_PER_SEC);
    //double numCells = ITERATIONS * query_len * 4 * ref_size * 4;
    double numCells = query_len * 4 * 4294967296;
    printf("Computation took %f seconds\n", timeSec);
    printf("Total cells computed: %f\n", numCells);
    printf("Performance: %f CUPS\n", numCells/timeSec);

    for (int i = 0; i < 128; i++) {
        printf("%i\t", results_buf[i]);
    }
    printf("\n");

    // streams are automatically closed when the PicoDrv object is destroyed, or on program termination, but
    //   we can also close a stream manually.
    pico->CloseStream(stream);
   
    return 0;
}

