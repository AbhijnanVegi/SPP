#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>

#include "benchmark.h"
#include "utils.h"

#ifndef BENCHMARK_IMPL
#define BENCHMARK_IMPL

#pragma STDC FP_CONTRACT OFF

Result single_benchmark(int vec_size, long loopcount);

Result benchmark(long loopcount)
{
    Timer t = newTimer();
    tick(t);

    int vec_size = 16;
#pragma omp parallel for
    for (int i = 0; i < omp_get_max_threads(); i++)
    {
        Result res = single_benchmark(vec_size, loopcount);
    }
    double time = tock(t);

    Result res = {vec_size, vec_size * 2 * omp_get_max_threads() * loopcount, 0, time};
    return res;
}

Result single_benchmark(int vec_size, long loopcount)
{
    srand(time(0));

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

    for (long i = 0; i < loopcount; i++)
    {
#pragma code_align 32
#ifndef __INTEL_COMPILER
        Y[0] = a * X[0] + Y[0];
        Y[1] = a * X[1] + Y[1];
        Y[2] = a * X[2] + Y[2];
        Y[3] = a * X[3] + Y[3];
        Y[4] = a * X[4] + Y[4];
        Y[5] = a * X[5] + Y[5];
        Y[6] = a * X[6] + Y[6];
        Y[7] = a * X[7] + Y[7];
        Y[8] = a * X[8] + Y[8];
        Y[9] = a * X[9] + Y[9];
        Y[10] = a * X[10] + Y[10];
        Y[11] = a * X[11] + Y[11];
        Y[12] = a * X[12] + Y[12];
        Y[13] = a * X[13] + Y[13];
        Y[14] = a * X[14] + Y[14];
        Y[15] = a * X[15] + Y[15];
        // Y[0] = fma(a, X[0], Y[0]);
        // Y[1] = fma(a, X[1], Y[1]);
        // Y[2] = fma(a, X[2], Y[2]);
        // Y[3] = fma(a, X[3], Y[3]);
        // Y[4] = fma(a, X[4], Y[4]);
        // Y[5] = fma(a, X[5], Y[5]);
        // Y[6] = fma(a, X[6], Y[6]);
        // Y[7] = fma(a, X[7], Y[7]);
        // Y[8] = fma(a, X[8], Y[8]);
        // Y[9] = fma(a, X[9], Y[9]);
        // Y[10] = fma(a, X[10], Y[10]);
        // Y[11] = fma(a, X[11], Y[11]);
        // Y[12] = fma(a, X[12], Y[12]);
        // Y[13] = fma(a, X[13], Y[13]);
        // Y[14] = fma(a, X[14], Y[14]);
        // Y[15] = fma(a, X[15], Y[15]);
#else
        for (int j = 0; j < vec_size; j++)
        {
            Y[j] = a * X[j] + Y[j];
            // Y[j] = fma(a, X[j], Y[j]);
        }
#endif
    }

    double time = tock(t);
    Result res = {vec_size, vec_size * 2 * loopcount, Y, time};
    return res;
}

#endif