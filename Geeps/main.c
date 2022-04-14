#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <omp.h>

#include "utils.h"

struct Result {
    double time;
    double e;
};

struct Result benchmark(void);

int num_words = (int)1e8;

int main() {
    printf("Running memory benchmark...\n");

    int runs = 100;

    double maxt, tott = 0;
    double mint = INT64_MAX;

    printf("Using %d threads\n", omp_get_max_threads());

    for (int i = 0; i < runs; i++) {
        struct Result res = benchmark();
        // printf("Run %d: %.2f seconds. Random output %lf\n", i, res.time, res.e);
        double t = res.time;
        tott += t;
        if (t < mint) mint = t;
        if (t > maxt) maxt = t;
    }

    double avgt = tott / runs;

    printf("Average Bandwidth\t%lf GB/s\n", (double)sizeof(long long) * num_words/avgt/1e9);
    printf("Avg\t\t\t%lf s\n", avgt);
    printf("Maximum Bandwidth\t%lf GB/s\n", (double)sizeof(long long) * num_words/mint/1e9);
    printf("Min\t\t\t%lf s\n", mint);
    printf("Minimum Bandwidth\t%lf GB/s\n", (double)sizeof(long long) * num_words/maxt/1e9);
    printf("Max\t\t\t%lf s\n", maxt);

    return 0;
}

struct Result benchmark(void) {
    long long *a = malloc(sizeof(long long) * num_words);
    long long *b = malloc(sizeof(long long) * num_words);

    Timer t = newTimer();

    double e = 0;

    tick(t);
    #pragma omp parallel for
    for (int i = 0; i < num_words; i++)
    {
        e = a[i];
    }
    double time = tock(t);

    free(a);
    free(b);

    struct Result res = {time, e};
    return res;
}