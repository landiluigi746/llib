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
LIB_DIR = lib
OUT_DIR = out

.PHONY: all examples llib run clean
all: examples

examples:
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(OUT_DIR)/darray examples/darray.c
	$(CC) $(CFLAGS) -o $(OUT_DIR)/list examples/list.c
	$(CC) $(CFLAGS) -o $(OUT_DIR)/memory examples/memory.c
	$(CC) $(CFLAGS) -o $(OUT_DIR)/utils examples/utils.c
	$(CC) $(CFLAGS) -o $(OUT_DIR)/string examples/string.c
	$(CC) $(CFLAGS) -o $(OUT_DIR)/io examples/io.c
	$(CC) $(CFLAGS) -o $(OUT_DIR)/algorithms examples/algorithms.c
	@echo "Done! Examples compiled. Use 'make run' to run them."
	make clean

llib:
	mkdir -p $(LIB_DIR)
	$(CC) -c $(CFLAGS)
	$(AR) rcs $(LIB_DIR)/llib.a $(LLIB_OBJ)
	@echo "Done! llib compiled as a static library 'llib.a'!"
	make clean

run:
	./$(OUT_DIR)/list
	./$(OUT_DIR)/memory
	./$(OUT_DIR)/utils
	./$(OUT_DIR)/string
	./$(OUT_DIR)/io
	./$(OUT_DIR)/algorithms

clean:
	$(RM) examples/*.o
	$(RM) $(LLIB_OBJ)