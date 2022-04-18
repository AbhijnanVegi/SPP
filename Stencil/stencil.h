#ifndef STENCIL_H
#define STENCIL_H

enum ImageType {HD, UHD};

void stencil(float *X, enum ImageType typ, int k, float *S, float *Y);

#endif