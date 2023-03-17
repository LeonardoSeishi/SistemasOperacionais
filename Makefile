# Makefile for SistemasOperacionais

CC = gcc
CFLAGS = -c -W -Wall -Wextra -ansi -pedantic

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cc)
INC_FILES = $(wildcard $(SRC_DIR)/*.h)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES),$(INC_FILES))

TARGET = SistemasOperacionais

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -i$(INC_DIR) -c -o $@ $<

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
