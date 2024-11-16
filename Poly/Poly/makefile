#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

poly: main.o poly-arr.o poly-ds.o
	$(CC) $(CFLAGS) -o poly main.o poly-arr.o poly-ds.o

poly-math.o: poly-arr.c
	$(CC) $(CFLAGS) -c poly-arr.c

poly-ds.o: poly-ds.c
	$(CC) $(CFLAGS) -c poly-ds.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f poly *.o