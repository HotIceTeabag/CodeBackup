#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

#
sort: main-sort.o module-sort.o
	$(CC) -o sort main-sort.o module-sort.o 

module-sort.o: module-sort.c
	$(CC) $(CFLAG) -c module-sort.c

main-sort.o: main-sort.c
	$(CC) $(CFLAG) -c main-sort.c

clean:
	rm -f sort *.o 



