#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct Result
{
    int size;
    long ops;
    double *res;
    double time;
} Result;

Result benchmark(long loopcount);

#endif