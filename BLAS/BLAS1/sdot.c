#include "cblas.h"

float cblas_sdot(const int N, const float *X, const int incX,
                 const float *Y, const int incY);

float cblas_sdot(const int N, const float *X, const int incX,
                 const float *Y, const int incY)
{
    float dot = 0.0;
#pragma omp parallel for reduction(+ \
                                   : dot)
    for (int i = 0; i < N / (incX > incY ? incX : incY); i++)
    {
        dot += X[i * incX] * Y[i * incY];
    }
    return dot;
}