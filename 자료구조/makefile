#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

#
datastructurre: main-ds.o module-ds.o
	$(CC) -o sort main-ds.o module-ds.o 

module-ds.o: module-ds.c
	$(CC) $(CFLAG) -c module-ds.c

main-ds.o: main-ds.c
	$(CC) $(CFLAG) -c main-ds.c

clean:
	rm -f *-ds.o 