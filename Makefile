CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -O0

SRC_DIR = src
BUILD_DIR = build
SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
BIN = nspsh

ifeq ($(OS),Windows_NT)
    BIN := $(BIN).exe
endif

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/ $(BIN)

run: $(BIN)
	./$(BIN)
