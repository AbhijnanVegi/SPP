#include <stdio.h>

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
    const float alpha = 1.5;
    const float beta = 0.8;

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

    float *A = frandarr(M * K);
    float *B = frandarr(K * N);
    float *C = frandarr(M * N);

    struct Timer *t = newTimer();

    tick(t);
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, alpha, A, K, B, N, beta, C, N);
    float time = tock(t);

    free(A);
    free(B);

    printf("Runtime : %lf\n", time);
    printf("Flops : %lf\n", ((float)M * N * K * 3 + M * N) / time / 1e9);
    printf("Bandwidth : %lf\n", (M * N + N * K + M * K) * sizeof(float) / time / 1e9);

    return 0;
}