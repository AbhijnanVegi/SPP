#include <stdio.h>
#include <cblas.h>

#include "cblas.h"
#include "utils.h"
#include "rand_utils.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <m> <n> <k>\n", argv[0]);
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

    int K = atoi(argv[3]);


    const int lda = N;

    double *A = drandarr(M * K);
    double *B = drandarr(K * N);
    double *C = drandarr(M * N);

    struct Timer *t = newTimer();

    tick(t);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, alpha, A, K, B, N, beta, C, N);
    double time = tock(t);

    free(A);
    free(B);
    free(C);

    printf("Runtime : %lf\n", time);
    printf("Flops : %lf\n", ((double)M * N * 3 + M) / time / 1e9);
    printf("Bandwidth : %lf\n", (M * N + M + N) * sizeof(double) / time / 1e9);

    return 0;
}