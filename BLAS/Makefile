INCLUDES = includes
BLAS1_SRC = BLAS1
BLAS2_SRC = BLAS2
BLAS3_SRC = BLAS3

CC = gcc
CFLAGS = -g -O3 -fopt-info -I$(INCLUDES) -march=native -mtune=native -fopenmp
all : blas1 blas2 blas3

blas1: $(BLAS1_SRC)/*.c
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

blas2: $(BLAS2_SRC)/*.c
	$(CC) $(CFLAGS) $(BLAS2_SRC)/sgemv.c -c
	$(CC) $(CFLAGS) $(BLAS2_SRC)/main_sgemv.c sgemv.o -o bin/sgemv

	$(CC) $(CFLAGS) $(BLAS2_SRC)/dgemv.c -c
	$(CC) $(CFLAGS) $(BLAS2_SRC)/main_dgemv.c dgemv.o -o bin/dgemv

blas3: $(BLAS3_SRC)/*.c
	$(CC) $(CFLAGS) $(BLAS3_SRC)/sgemm.c -c
	$(CC) $(CFLAGS) $(BLAS3_SRC)/main_sgemm.c sgemm.o -o bin/sgemm

	$(CC) $(CFLAGS) $(BLAS3_SRC)/dgemm.c -c
	$(CC) $(CFLAGS) $(BLAS3_SRC)/main_dgemm.c dgemm.o -o bin/dgemm



cblas:
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c -o bin/sscal -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_dscal.c -o bin/dscal -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sdot.c -o bin/sdot -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_ddot.c -o bin/ddot -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_saxpy.c -o bin/saxpy -lcblas
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_daxpy.c -o bin/daxpy -lcblas

	$(CC) $(CFLAGS) $(BLAS2_SRC)/main_sgemv.c -o bin/sgemv -lcblas
	$(CC) $(CFLAGS) $(BLAS2_SRC)/main_dgemv.c -o bin/dgemv -lcblas

	$(CC) $(CFLAGS) $(BLAS3_SRC)/main_sgemm.c -o bin/sgemm -lcblas
	$(CC) $(CFLAGS) $(BLAS3_SRC)/main_dgemm.c -o bin/dgemm -lcblas
	
blis:
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sscal.c /usr/local/lib/libblis.a -o bin/sscal -lm -I/usr/local/include/blis
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_dscal.c /usr/local/lib/libblis.a -o bin/dscal -lm -I/usr/local/include/blis
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_sdot.c /usr/local/lib/libblis.a -o bin/sdot -lm -I/usr/local/include/blis
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_ddot.c /usr/local/lib/libblis.a -o bin/ddot -lm -I/usr/local/include/blis
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_saxpy.c /usr/local/lib/libblis.a -o bin/saxpy -lm -I/usr/local/include/blis
	$(CC) $(CFLAGS) $(BLAS1_SRC)/main_daxpy.c /usr/local/lib/libblis.a -o bin/daxpy -lm -I/usr/local/include/blis

	$(CC) $(CFLAGS) $(BLAS2_SRC)/main_sgemv.c /usr/local/lib/libblis.a -o bin/sgemv -lm -I/usr/local/include/blis
	$(CC) $(CFLAGS) $(BLAS2_SRC)/main_dgemv.c /usr/local/lib/libblis.a -o bin/dgemv -lm -I/usr/local/include/blis

	$(CC) $(CFLAGS) $(BLAS3_SRC)/main_sgemm.c /usr/local/lib/libblis.a -o bin/sgemm -lm -I/usr/local/include/blis
	$(CC) $(CFLAGS) $(BLAS3_SRC)/main_dgemm.c /usr/local/lib/libblis.a -o bin/dgemm -lm -I/usr/local/include/blis

clean: 
	rm *.o *.optrpt *.data *.data.old bin/*