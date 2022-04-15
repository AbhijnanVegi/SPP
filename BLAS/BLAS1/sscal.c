#include "cblas.h"

void cblas_sscal(const int N, const float alpha, float *X, const int incX);

void cblas_sscal(const int N, const float alpha, float *X, const int incX)
{
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        X[i * incX] *= alpha;
    }
}