INCLUDES = includes
BLAS1_SRC = BLAS1

CC = gcc
CFLAGS = -g -O3 -fopt-info -I$(INCLUDES) -mavx2 -mfma -march=native -mtune=native -fopenmp
all : blas1

blas1: $(BLAS1_SRC)/main_sscal.c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/sscal.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c sscal.o -o bin/sscal 
	$(CC) $(CFLAGS) $(BLAS1_SRC)/dscal.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_dscal.c dscal.o -o bin/dscal 

blis:
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c -o bin/sscal -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_dscal.c -o bin/dscal -lcblas

clean: 
	rm *.o *.optrpt bin/*