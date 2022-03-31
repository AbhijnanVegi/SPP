#include <stdlib.h>
#include <time.h>

#include "benchmark.h"
#include "utils.h"

#ifndef BENCHMARK_IMPL
#define BENCHMARK_IMPL

Result benchmark(long loopcount)
{
    srand(time(0));

    int vec_size = 8;
    double a = (double)rand() / RAND_MAX;
    double *X = malloc(vec_size * sizeof(double));
    double *Y = malloc(vec_size * sizeof(double));

    for (int i = 0; i < vec_size; i++)
    {
        X[i] = (double)rand() / RAND_MAX;
        Y[i] = (double)rand() / RAND_MAX;
    }

    Timer t = newTimer();
    tick(t);
    // #pragma omp parallel for
    for (int i = 0; i < loopcount; i++)
    {
        #pragma code_align 32
        for (int i = 0; i < vec_size; i++)
        {
            Y[i] = a * X[i] + Y[i];
        }
    }
    double time = tock(t);
    Result res = {vec_size, vec_size * 2 * loopcount, Y, time};
    return res;
}

#endif