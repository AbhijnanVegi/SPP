#include <stdio.h>
#include <stdlib.h>

#include "stencil.h"
#include "utils.h"

int main(int argc, char* argv[]) {

    int k = 3;
    if (argc == 2) {
        k = atoi(argv[1]);
        if (k < 0) 
        {
            printf("k must be positive\n");
            exit(1);
        }
    }

    enum ImageType typ = HD;

    float *X, *S, *Y;
    int nx, ny;
    if (typ == HD)
    {
        nx = 1920;
        ny = 1080;
    }
    else if (typ == UHD)
    {
        nx = 3840;
        ny = 2160;
    }

    X = (float*)malloc(nx * ny * sizeof(float));
    Y = (float*)malloc(nx * ny * sizeof(float));
    S = (float *) malloc(k * k * sizeof(float));

    Timer t = newTimer();

    tick(t);
    stencil(X, typ, k, S, Y);
    double time = tock(t);

    free(X);
    free(S);
    free(Y);

    printf("Runtime : %lf\n", time);
    printf("Flops : %lf\n", (double)nx * ny * k * k * 2 / time/1e9);
    printf("Bandwidth : %lf\n", (double)2 * nx * ny * sizeof(float) / time / 1e9);

    return 0;
}