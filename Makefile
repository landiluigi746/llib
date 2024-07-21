# Makefile for examples
#
# Author: landiluigi746
# Date: 2024-07-09
# Github: https://github.com/landiluigi746

CC = gcc
AR = ar
LLIB_SRC = src/llib/*.c
LLIB_OBJ = ./*.o
CFLAGS = $(LLIB_SRC) -std=c99 -Iinclude
RM = rm -f

.PHONY: all examples llib run clean
all: examples

examples:
	$(CC) $(CFLAGS) -o examples/list examples/list.c
	$(CC) $(CFLAGS) -o examples/memory examples/memory.c
	$(CC) $(CFLAGS) -o examples/utils examples/utils.c
	$(CC) $(CFLAGS) -o examples/string examples/string.c
	$(CC) $(CFLAGS) -o examples/io examples/io.c
	$(CC) $(CFLAGS) -o examples/algorithms examples/algorithms.c
	@echo "Done! Examples compiled. Use 'make run' to run them."
	make clean

llib:
	$(CC) -c $(CFLAGS)
	$(AR) rcs libllib.a $(LLIB_OBJ)
	@echo "Done! llib compiled as a static library 'libllib.a'!"
	make clean

run:
	./examples/memory
	./examples/utils
	./examples/string
	./examples/io
	./examples/algorithms

clean:
	$(RM) examples/*.o
	$(RM) $(LLIB_OBJ)