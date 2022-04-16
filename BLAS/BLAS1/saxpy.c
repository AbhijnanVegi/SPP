#include "cblas.h"

void cblas_saxpy(const int N, const float alpha, const float *X,
                 const int incX, float *Y, const int incY);

void cblas_saxpy(const int N, const float alpha, const float *X,
                 const int incX, float *Y, const int incY)
{
    // #pragma omp parallel for
    for (int i = 0; i < N / (incX > incY ? incX : incY); i++)
    {
        Y[i * incY] += alpha * X[i * incX];
    }
}