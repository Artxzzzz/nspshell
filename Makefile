CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -O0


SRC = $(wildcard *.c packages/*.c helpers/*.c welcome/*.c)
OBJ = $(patsubst %.c,build/%.o,$(SRC))
bin = nspsh

ifeq ($(OS),Windows_NT)
    bin := $(bin).exe
endif

all: $(bin)


$(bin): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/ $(bin)


run: $(bin)
	./$(bin)