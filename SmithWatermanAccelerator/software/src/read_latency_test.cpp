#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

int main (int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./read_latency_test <FILE>" << std::endl;
    return 1;
  }

  std::string filename(argv[1]);

  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return 1;
  }

  char *buffer = new char [100];

  struct timespec start, finish;
  double elapsed;

#ifdef __MACH__
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  start.tv_sec = mts.tv_sec;
  start.tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_MONOTONIC, &start);
#endif

  file.seekg(5);
  file.read(buffer, 100);

#ifdef __MACH__
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  finish.tv_sec = mts.tv_sec;
  finish.tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_MONOTONIC, &finish);
#endif

  file.close();

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

  std::cout.write(buffer, 100);
  std::cout << std::endl;
  std::cout << "Elapsed: " << elapsed << " seconds" << std::endl;
  return 0;
}
