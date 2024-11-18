#
# makefile
#

CC = gcc
CFLAGS = -Wall -Wextra -O2
ASMFLAGS = -S

SRC = main.c arr.c
HDR = comb.h
OBJ = $(SRC:.c=.o)
ASM = $(SRC:.c=.s)
TARGET = program

all: $(TARGET) asm


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


asm: $(ASM)


%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@


%.s: %.c $(HDR)
	$(CC) $(CFLAGS) $(ASMFLAGS) $< -o $@


clean:
	rm -f $(OBJ) $(ASM) $(TARGET)
