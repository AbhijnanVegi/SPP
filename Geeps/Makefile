CC = gcc
CFLAGS = -g -fopenmp -O3 -fopt-info

all: main.c 
	$(CC) $(CFLAGS) -c utils.c
	$(CC) $(CFLAGS) main.c utils.o -o bench

clean:
	rm -f *.o bench