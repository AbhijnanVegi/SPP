#include "cblas.h"
#include "omp.h"

double cblas_ddot(const int N, const double *X, const int incX,
                 const double *Y, const int incY);

double cblas_ddot(const int N, const double *X, const int incX,
                 const double *Y, const int incY)
{
    double dot = 0.0;
#pragma omp parallel for reduction(+ \
                                   : dot)
    for (int i = 0; i < N / (incX > incY ? incX : incY); i++)
    {
        dot += X[i * incX] * Y[i * incY];
    }
    return dot;
}