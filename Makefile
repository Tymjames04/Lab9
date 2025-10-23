CC=g++
CFLAGS= -c -Wall

all: matrix

matrix: matrix.o
	$(CC) matrix.o -o matrix
	rm -rf *.o

matrix.o: matrix.cpp
	$(CC) $(CFLAGS) matrix.cpp

clean:
	rm matrix
