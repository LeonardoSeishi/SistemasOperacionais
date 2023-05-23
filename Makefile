CC = g++
CFLAGS = -w -Wall -Wextra -ansi -pedantic -std=c++11

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cc)
INC_FILES = $(wildcard $(INC_DIR)/*.h)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
