#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

#
matrix: main-matrix.o module-matrix.o
	$(CC) -o matrix main-matrix.o module-matrix.o 

module-matrix.o: module-matrix.c
	$(CC) $(CFLAG) -c module-matrix.c

main-matrix.o: main-matrix.c
	$(CC) $(CFLAG) -c main-matrix.c

clean:
	rm -f matrix *.o 
