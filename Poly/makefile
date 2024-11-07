#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

#
poly: main.o poly-math.o poly-ds.o
	$(CC) -o main.o poly-math.o poly-ds.o

poly-math.o: poly-math.c
	$(CC) $(CFLAGS) -c poly-math.c

poly-ds.o: poly-ds.c
	$(CC) $(CFLAGS) -c poly-ds.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f poly poly-*.o  
