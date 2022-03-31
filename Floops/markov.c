#include <stdlib.h>

#include "benchmark.h"
#include "utils.h"

#ifndef BENCHMARK_IMPL
#define BENCHMARK_IMPL
Result benchmark(long loopcount) {
    double a = 0.5f, x = 1.0f, c = 1.0f;
    Timer t = newTimer();
    tick(t);
    for (long i = 0; i < loopcount; i++)
    {
        x = a * x + c;
    }
    double time = tock(t);
    double *ret = malloc(sizeof(double));
    *ret = x;
    Result res = {1, 2*loopcount, ret, time};
    return res;
}
#endif