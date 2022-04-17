#include <stdlib.h>
#include "benchmark.h"
#include "utils.h"

struct Result benchmark(int num_words) {
    long long *a = (long long *)malloc(sizeof(long long) * num_words);
    long long *b = (long long *)malloc(sizeof(long long) * num_words);

    Timer t = newTimer();

    long long e = 0;

    tick(t);
    #pragma omp parallel for
    for (int i = 0; i < num_words; i++)
    {
        e = b[i] - a[i];
    }
    double time = tock(t);

    free(a);

    struct Result res = {time, e};
    return res;
}