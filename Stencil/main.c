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
        }
        exit(1);
    }

    enum ImageType typ = HD;

    float *X, *S, *Y;
    if (typ == HD)
    {
        X = (float *) malloc(1920 * 1080 * sizeof(float));
        S = (float *) malloc(k * k * sizeof(float));
        Y = (float *) malloc(1920 * 1080 * sizeof(float));
    }
    else if (typ == UHD)
    {
        X = (float *) malloc(3840 * 2160 * sizeof(float));
        S = (float *) malloc(k * k * sizeof(float));
        Y = (float *) malloc(3840 * 2160 * sizeof(float));
    }

    Timer t = newTimer();

    tick(t);
    stencil(X, typ, k, S, Y);
    double time = tock(t);

    free(X);
    free(S);
    free(Y);

    printf("Runtime : %lf\n", time);

    return 0;
}