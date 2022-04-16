#include "cblas.h"

void cblas_dscal(const int N, const double alpha, double *X, const int incX);

void cblas_dscal(const int N, const double alpha, double *X, const int incX)
{
    #pragma omp parallel for
    for (int i = 0; i < N/ incX; i++)
    {
        X[i * incX] *= alpha;
    }
}