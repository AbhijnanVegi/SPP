#include <stdio.h>
#include "cblas.h"

void cblas_sgemv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY);

void cblas_sgemv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY)
{
    int i, j;
    int lenX, lenY;

    const int Trans = (TransA != CblasConjTrans) ? TransA : CblasTrans;

    if (Trans == CblasNoTrans)
    {
        lenX = N;
        lenY = M;
    }
    else
    {
        lenX = M;
        lenY = N;
    }

#pragma omp parallel for
    for (int i = 0; i < lenY; i += incY)
    {
        Y[i] *= beta;
    }

    if ((order == CblasRowMajor && Trans == CblasNoTrans) || (order == CblasColMajor && Trans == CblasTrans))
    {
#pragma omp parallel for
        for (int i = 0; i < lenY; i += incY)
        {
            float temp = 0.0;
            #pragma omp parallel for reduction(+ : temp)
            for (j = 0; j < lenX; j += incX)
            {
                temp += X[j] * A[lda * i + j];
            }
            Y[i] += alpha * temp;
        }
    }
    else if ((order == CblasRowMajor && Trans == CblasTrans) || (order == CblasColMajor && Trans == CblasNoTrans))
    {
        for (j = 0; j < lenX; j += incX)
        {
            const float temp = alpha * X[j];
            #pragma omp parallel for num_threads(2)
            for (i = 0; i < lenY; i += incY)
            {
                Y[i] += temp * A[lda * j + i];
            }
        }
    }
}