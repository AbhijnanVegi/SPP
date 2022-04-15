INCLUDES = includes
BLAS1_SRC = BLAS1

CC = gcc
CFLAGS = -g -O3 -fopt-info -I$(INCLUDES) -mavx2 -mfma -march=native -mtune=native

all : blas1

blas1: $(BLAS1_SRC)/*
	$(CC) $(CFLAGS) $(BLAS1_SRC)/sscal.c -c
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c sscal.o -o bin/sscal 

blis:
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c -o bin/sscal -lcblas

clean: 
	rm *.o bin/*