# Variables
CC = gcc
CFLAGS = -Wall
SRC = sample.c
OUT = main

# Default Target
all: $(OUT)

# Compile
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean Target
clean:
	rm -f $(OUT)

