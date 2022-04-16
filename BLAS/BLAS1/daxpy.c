#include "cblas.h"

void cblas_daxpy(const int N, const double alpha, const double *X,
                 const int incX, double *Y, const int incY);

void cblas_daxpy(const int N, const double alpha, const double *X,
                 const int incX, double *Y, const int incY)
{
    // #pragma omp parallel for
    for (int i = 0; i < N / (incX > incY ? incX : incY); i++)
    {
        Y[i * incY] += alpha * X[i * incX];
    }
}