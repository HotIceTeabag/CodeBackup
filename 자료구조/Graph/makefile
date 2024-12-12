#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

#
graph: main.o graph.o algorithm.o 
	$(CC) -o graph main.o graph.o algorithm.o

algorithm.o: algorithm.c
	$(CC) $(CFLAGS) -c algorithm.c

graph.o: graph.c
	$(CC) $(CFLAGS) -c graph.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f sort *.o 



