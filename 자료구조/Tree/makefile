#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

#
tree: main.o trees.o huffman.o
	$(CC) -o tree main.o trees.o huffman.o

huffman.o: huffman.c
	$(CC) $(CFLAGS) -c huffman.c

trees.o: trees.c
	$(CC) $(CFLAGS) -c trees.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o 