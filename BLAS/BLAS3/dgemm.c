#include "cblas.h"

void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc);

void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc)
{
    const double *X, *Y;
    int TransX, TransY;
    int ldx, ldy;

    int t1, t2;

    if (Order == CblasRowMajor)
    {
        X = A;
        Y = B;

        t1 = M;
        t2 = N;

        TransX = TransA;
        TransY = TransB;

        ldx = lda;
        ldy = ldb;
    }
    else
    {
        X = B;
        Y = A;

        t1 = N;
        t2 = M;

        TransX = TransB;
        TransY = TransA;

        ldx = ldb;
        ldy = lda;
    }

    for (int i = 0; i < t1; i++)
    {
        for (int j = 0; j < t2; j++)
        {
            C[ldc * i + j] *= beta;
        }
    }

    if (TransX == CblasNoTrans && TransY == CblasNoTrans)
    {
        for (int k = 0; k < K; k++)
        {
            for (int i = 0; i < t1; i++)
            {
                const double temp = alpha * X[ldx * i + k];
                if (temp != 0.0)
                {
                    for (int j = 0; j < t2; j++)
                    {
                        C[ldc * i + j] += temp * Y[ldy * k + j];
                    }
                }
            }
        }
    }
    else if (TransX == CblasTrans && TransY == CblasTrans)
    {
        for (int i = 0; i < t1; i++)
        {
            for (int j = 0; j < t2; j++)
            {
                double temp = 0.0;
                for (int k = 0; k < K; k++)
                {
                    temp += X[ldx * k + i] * Y[ldy * j + k];
                }
                C[ldc * i + j] += alpha * temp;
            }
        }
    }
    else if (TransX == CblasTrans && TransY == CblasNoTrans)
    {
        for (int k = 0; k < K; k++)
        {
            for (int i = 0; i < t1; i++)
            {
                const double temp = alpha * X[ldx * k + i];
                if (temp != 0.0)
                {
                    for (int j = 0; j < t2; j++)
                    {
                        C[ldc * i + j] += temp * Y[ldy * k + j];
                    }
                }
            }
        }
    }
    else if (TransX == CblasNoTrans && TransY == CblasTrans)
    {
        for (int i = 0; i < t1; i++)
        {
            for (int j = 0; j < t2; j++)
            {
                double temp = 0.0;
                for (int k = 0; k < K; k++)
                {
                    temp += X[ldx * i + k] * Y[ldy * j + k];
                }
                C[ldc * i + j] += alpha * temp;
            }
        }
    }
}