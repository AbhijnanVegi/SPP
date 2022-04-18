#include <stdio.h>
#include <cblas.h>

#include "cblas.h"
#include "utils.h"
#include "rand_utils.h"

int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4 && argc != 5)
    {
        printf("Usage: %s <m> <n> <incX> <incY>\n", argv[0]);
        return 1;
    }

    // Defaults
    const double alpha = 1.5;
    const double beta = 0.8;

    int M = atoi(argv[1]);
    if (M <= 0)
    {
        printf("M must be positive\n");
        return 1;
    }

    int N = atoi(argv[2]);
    if (N <= 0)
    {
        printf("N must be positive\n");
        return 1;
    }

    int incx = 1;
    int incy = 1;
    const int lda = N;

    if (argc > 3)
    {
        incx = atoi(argv[3]);
        if (incx <= 0)
        {
            printf("incX must be positive\n");
            return 1;
        }
    }

    if (argc == 5)
    {
        incy = atoi(argv[4]);
        if (incy <= 0)
        {
            printf("incY must be positive\n");
            return 1;
        }
    }

    double *X = drandarr(N);
    double *Y = drandarr(M);
    double *A = drandarr(M * N);

    struct Timer *t = newTimer();

    tick(t);
    cblas_dgemv(CblasRowMajor, CblasNoTrans, M, N, alpha, A, lda, X, incx, beta, Y, incy);
    double time = tock(t);

    free(X);
    free(Y);
    free(A);

    printf("Runtime : %lf\n", time);
    printf("Flops : %lf\n", ((double)M * N * 3 + M) / time / 1e9);
    printf("Bandwidth : %lf\n", (M * N + M + N) * sizeof(double) / time / 1e9);

    return 0;
}