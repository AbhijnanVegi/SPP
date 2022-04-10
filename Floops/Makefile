CC = icc
CFLAGS = -g -O3 -mfma -mavx2 -qopt-report -qopenmp 
# CFLAGS = -g -O3 -mfma -mavx2 
INCLUDES = includes
OBJECTS = utils.o

all: markov blas1

markov: main.c markov.c utils.o
	$(CC) markov.c $(OBJECTS) $(CFLAGS) -c -I$(INCLUDES)
	$(CC) main.c markov.o $(OBJECTS) $(CFLAGS) -o bin/markov -I$(INCLUDES) 

blas1: main.c blas1.c utils.o
	$(CC) blas1.c $(OBJECTS) $(CFLAGS) -c -I$(INCLUDES)
	$(CC) main.c blas1.o $(OBJECTS) $(CFLAGS) -o bin/blas1 -I$(INCLUDES)

utils.o: utils.c
	$(CC) -g -c utils.c -I${INCLUDES}

clean:
	rm *.o