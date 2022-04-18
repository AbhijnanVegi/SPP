CC = gcc
CFLAGS = -O3 -g -fopenmp -march=native -mtune=native -fopt-info

all: main.c stencil.c
	$(CC) $(CFLAGS) stencil.c -c
	$(CC) $(CFLAGS) main.c stencil.o -o stencil