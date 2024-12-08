#
# makefile
#

CC = gcc
CFLAGS = -Wall -g

#
mat_opt: main.o func.o
	$(CC) -o mat_opt main.o func.o 

func.o: func.c
	$(CC) $(CFLAGS) -c func.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f matrix *.o 
