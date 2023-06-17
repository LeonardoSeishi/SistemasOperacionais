CC = g++
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
CFLAGS = -I$(INC_DIR) -g -w -Wall -Wextra -ansi -pedantic -std=c++11

LDFLAGS = $(CFLAGS)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm -lpng -g

SRC_FILES = $(wildcard $(SRC_DIR)/*.cc)
INC_FILES = $(wildcard $(INC_DIR)/*.h)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))

_DEPS = window.h
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))

LIBS = $(LDLIBS) $(LDFLAGS)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)