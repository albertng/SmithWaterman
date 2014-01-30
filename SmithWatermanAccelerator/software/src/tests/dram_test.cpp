#include <iostream>
#include <time.h>
#include <picodrv.h>
#include <pico_errors.h>

int main(int argc, char *argv[]) {
  PicoDrv *pico;

  if (argc < 3) {
    std::cerr << "Usage: ./dram_test <BIT_FILE> <NUM_PACKET>" << std::endl;;
    return 1;
  }
  
  // Set up pico FPGA drivers
  const char* bitfile_name = argv[1];
  std::cout << "Loading FPGA with bitfile: " << bitfile_name << std::endl;
  int err = RunBitFile(bitfile_name, &pico);
  if (err < 0) {
    std::cerr << "RunBitFile error: " << PicoErrors_FullError << "\n";
    return 1;
  }
  
  int num_packets = atoi(argv[2]);
  
  // DRAM WRITE PERFORMANCE TEST
  std::cout << "Running performance test with " << num_packets << " packets..." << std::endl;
  char* test_buf = new char[1024*1024*1024];
  char ibuf[1024];
  struct timespec start, finish;
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < num_packets; i++) {
    int err = pico->WriteRam(i * (1024 * 1024 * 1024 / num_packets), test_buf, (1024 * 1024 * 1024 / num_packets), PICO_DDR3_0);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    if (err < 0){
        fprintf(stderr, "WriteRam error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    } else if (err != (1024 * 1024 * 1024 / num_packets)){
        fprintf(stderr, "WriteRam wrote %i bytes instead of the desired %i bytes\n", err, (1024 * 1024 * 1024 / num_packets));
        exit(1);
    }
  }
  clock_gettime(CLOCK_MONOTONIC, &finish);
  double elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout << "1 GB DRAM write completed in " << elapsed << " seconds." << std::endl;
  exit(0);
}
