CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -O0

SRC_DIR = src
OBJ_DIR = ../build/externals

ifeq ($(OS),Windows_NT)
    EXT = .exe
else
    EXT =
endif

SOURCES := $(shell find $(SRC_DIR) -name "*.c")

EXECUTABLES := $(notdir $(SOURCES:.c=$(EXT)))

all: $(EXECUTABLES)

$(foreach src,$(SOURCES),$(eval $(notdir $(src:.c=$(EXT))): $(src)))

nobuild: all
	@sleep 0.85 # prevents race condition, if you remove, have the chance of dont work, if you remove you are a devil

	rm -rf ../build


%$(EXT):
	@mkdir -p $(OBJ_DIR)

	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$(notdir $(basename $<)).o

	$(CC) $(CFLAGS) $(OBJ_DIR)/$(notdir $(basename $<)).o -o $@

clean:
	rm -rf ../build
	rm -f $(EXECUTABLES)