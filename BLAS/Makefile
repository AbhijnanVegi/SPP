INCLUDES = includes
BLAS1_SRC = BLAS1

CC = gcc
CFLAGS = -g -O3 -fopt-info -I$(INCLUDES) -march=native -mtune=native -fopenmp
all : blas1

blas1: $(BLAS1_SRC)/main_sscal.c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/sscal.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c sscal.o -o bin/sscal 

	$(CC) $(CFLAGS) $(BLAS1_SRC)/dscal.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_dscal.c dscal.o -o bin/dscal 

	$(CC) $(CFLAGS) $(BLAS1_SRC)/sdot.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sdot.c sdot.o -o bin/sdot

	$(CC) $(CFLAGS) $(BLAS1_SRC)/ddot.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_ddot.c ddot.o -o bin/ddot

	$(CC) $(CFLAGS) $(BLAS1_SRC)/saxpy.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_saxpy.c saxpy.o -o bin/saxpy

	$(CC) $(CFLAGS) $(BLAS1_SRC)/daxpy.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_daxpy.c daxpy.o -o bin/daxpy


cblas:
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c -o bin/sscal -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_dscal.c -o bin/dscal -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sdot.c -o bin/sdot -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_ddot.c -o bin/ddot -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_saxpy.c -o bin/saxpy -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_daxpy.c -o bin/daxpy -lcblas
	

clean: 
	rm *.o *.optrpt *.data *.data.old bin/*