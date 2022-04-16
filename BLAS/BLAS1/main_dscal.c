#include <stdio.h>

#include "cblas.h"
#include "utils.h"
#include "rand_utils.h"

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        printf("Usage: %s <n> <stride>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("N must be positive\n");
        return 1;
    }

    int stride = 1;

    if (argc == 3) {
        stride = atoi(argv[2]);
        if (stride <= 0) {
            printf("stride must be positive\n");
            return 1;
        }
    }

    double *X = drandarr(N);

    struct Timer* t = newTimer();

    tick(t);
    cblas_dscal(N, 1.5, X, stride);

    free(X);

    double time = tock(t);

    printf("Runtime : %lf\n", time);
    printf("Flops : %lf\n", (double) N / stride / time / 1e9);
    printf("Bandwidth : %lf\n", (double) N * sizeof(double) / time / 1e9);

    return 0;
}