#include <stdio.h>
#include <iostream>
#include <time.h>

int main(void) {
    clock_t begin = clock();
    sleep(5);
    clock_t end = clock();
    double timeSec = (end - begin) / ((double) CLOCKS_PER_SEC);
    printf("Time: %f\n", timeSec);

    struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
    sleep(5);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Time: %f\n", elapsed);
    return 0;
}
