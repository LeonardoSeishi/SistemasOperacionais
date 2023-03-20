CC = g++
CFLAGS = -W -Wall -Wextra -ansi -pedantic -std=c++11

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cc)
INC_FILES = $(wildcard $(INC_DIR)/*.h)

# OBJ_FILES = $(subst .c,.o,$(subst source,objects,$(SRC_FILES)))

OBJ_FILES = $(filter-out $(OBJ_DIR)/cpu.o, $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))) $(patsubst $(INC_DIR)/%.h,$(OBJ_DIR)/%.o,$(INC_FILES)) $(OBJ_DIR)/cpu.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

$(OBJ_DIR)/%.o: $(INC_DIR)/%.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

$(OBJ_DIR)/cpu.o: $(SRC_DIR)/cpu.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
