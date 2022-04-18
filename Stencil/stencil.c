#include "stencil.h"

void stencil(float *X, enum ImageType typ, int k, float *S, float *Y)
{
    int dimX, dimY;

    if (typ == HD)
    {
        dimX = 1920;
        dimY = 1080;
    }
    else if (typ == UHD)
    {
        dimX = 3840;
        dimY = 2160;
    }

    int i, j;
    int kx, ky;

#pragma omp parallel for
    for (i = 0; i < dimY; i++)
    {
        for (j = 0; j < dimX; j++)
        {
            Y[i * dimX + j] = 0.0;
            for (kx = 0; kx < k; kx++)
            {
                if (i + kx >= dimY)
                    break;
                for (ky = 0; ky < k; ky++)
                {
                    if (j + ky >= dimX)
                        break;
                    Y[i * dimX + j] += X[(i + kx) * dimX + (j + ky)] * S[kx * k + ky];
                }
            }
        }
    }
}