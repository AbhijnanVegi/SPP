#include <stdio.h>
#include <stdlib.h>

#include "benchmark.h"

int main(int argc, char* argv[]) {

    long loopcount = 1e9;
    if (argc > 1)
    {
        if (atol(argv[1]) > 0) {
            loopcount = atol(argv[1]);
        } else {
            printf("Invalid loopcount! Value ignored");
        }
    }
    
    Result r = benchmark(loopcount);

    double flops = r.ops / r.time / 1e9;
    printf("Operations : %ld\n", r.ops);
    printf("Performance : %lf GFLOPS\n", flops);
    printf("Runtime : %lf\n", r.time);
    return 0;
}
