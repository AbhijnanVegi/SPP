#include <stdio.h>

#include "cblas.h"
#include "utils.h"
#include "rand_utils.h"

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3 && argc != 4) {
        printf("Usage: %s <n> <stride>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("N must be positive\n");
        return 1;
    }

    int incx = 1;
    int incy = 1;
    double alpha = 1.5;

    if (argc >= 3) {
        incx = atoi(argv[2]);
        if (incx <= 0) {
            printf("incX must be positive\n");
            return 1;
        }
    }

    if (argc == 4) {
        incy = atoi(argv[3]);
        if (incy <= 0) {
            printf("incY must be positive\n");
            return 1;
        }
    }

    float *X = frandarr(N);
    float *Y = frandarr(N);

    struct Timer* t = newTimer();

    tick(t);
    cblas_saxpy(N, alpha, X, incx, Y, incy);
    free(X);

    double time = tock(t);

    printf("Runtime : %lf\n", time);
    printf("Flops : %lf\n", (double)2 * N / (incx > incy ? incx : incy ) / time / 1e9);
    printf("Bandwidth : %lf\n", 2 * (double) N * sizeof(float) / time / 1e9);

    return 0;
}