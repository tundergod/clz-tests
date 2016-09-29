#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};
    if (argc < 2) return -1;
    int N = atoi(argv[1]);
    int i;
    int x = 1;

    for(i = 0; i < N; i++) {
    printf("%d ",i);

    // clz_recursive
    clock_gettime(CLOCK_ID, &start);
    clz_recursive(x,16);
    clock_gettime(CLOCK_ID, &end);
    printf("%.10lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

 // clz_iterative
    clock_gettime(CLOCK_ID, &start);
    clz_iteration(x);
    clock_gettime(CLOCK_ID, &end);
    printf("%.10lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

 // clz_binary search
    clock_gettime(CLOCK_ID, &start);
    clz_binary(x);
    clock_gettime(CLOCK_ID, &end);
    printf("%.10lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

 // clz_byte shift
    clock_gettime(CLOCK_ID, &start);
        clz_byte(x);
    clock_gettime(CLOCK_ID, &end);
    printf("%.10lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

 // clz_harley's algorithm
    clock_gettime(CLOCK_ID, &start);
        clz_harley(x);
    clock_gettime(CLOCK_ID, &end);
    printf("%.10lf ", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    printf("\n");
    }

}
