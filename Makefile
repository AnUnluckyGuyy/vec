CC = gcc                # compiler
CFLAGS = -Wall -Wextra -Iinclude   # compiler flags
SRC = src/vec.c
OBJ = build/vec.o
LIB = build/libvec.a
TEST = build/test

# Default target: build the library and test
all: $(LIB) $(TEST)

# Compile the library object
$(OBJ): $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Create the static library
$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

# Compile the test program
$(TEST): tests/test.c $(LIB)
	$(CC) $(CFLAGS) tests/test.c -Lbuild -lvec -o $(TEST)

# Clean up
clean:
	rm -rf build/*
