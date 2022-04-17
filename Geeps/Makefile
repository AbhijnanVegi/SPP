CC = gcc
CFLAGS = -g -fopenmp -O2 -fopt-info

all: main.c 
	$(CC) $(CFLAGS) -c utils.c
	$(CC) $(CFLAGS) -c benchmark.c
	$(CC) $(CFLAGS) main.c benchmark.o utils.o -o bench

clean:
	rm -f *.o bench