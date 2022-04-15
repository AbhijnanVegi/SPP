#ifndef RAND_UTILS_H
#define RAND_UTILS_H

#include <stdio.h>
#include <stdlib.h>

float* frandarr(int n) {
    float *X = (float*)malloc(sizeof(float) * n);

    if (X == NULL) {
        printf("Error intialising array\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        X[i] = drand48();
    }

    return X;
}

double* drandarr(int n) {
    double *X = (double*)malloc(sizeof(double) * n);

    if (X == NULL) {
        printf("Error intialising array\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        X[i] = drand48();
    }

    return X;
}

#endif