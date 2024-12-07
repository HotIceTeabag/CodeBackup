CC = gcc
CFLAGS = -g -Wall

main: main.o node.o stack.o tree.o
	$(CC) -o main main.o node.o stack.o tree.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
node.o: node.c
	$(CC) $(CFLAGS) -c node.c
stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c
tree.o: tree.c
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f main *.o