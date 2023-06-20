CC = g++

THR_DIR = thread
GAM_DIR = game
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

CFLAGS = -I$(GAM_DIR)/$(INC_DIR) -I$(THR_DIR)/$(INC_DIR) -g -w -Wall -Wextra -ansi -pedantic -std=c++11
LDFLAGS = $(CFLAGS)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm -lpng -g

GAM_SRC_FILES = $(wildcard $(GAM_DIR)/$(SRC_DIR)/*.cc)
THR_SRC_FILES = $(wildcard $(THR_DIR)/$(SRC_DIR)/*.cc)
GAM_INC_FILES = $(wildcard $(GAM_DIR)/$(INC_DIR)/*.h)
THR_INC_FILES = $(wildcard $(THR_DIR)/$(INC_DIR)/*.h)
GAM_OBJ_FILES = $(patsubst $(GAM_DIR)/$(SRC_DIR)/%.cc,$(GAM_DIR)/$(OBJ_DIR)/%.o,$(GAM_SRC_FILES))
THR_OBJ_FILES = $(patsubst $(THR_DIR)/$(SRC_DIR)/%.cc,$(THR_DIR)/$(OBJ_DIR)/%.o,$(THR_SRC_FILES))

LIBS = $(LDLIBS) $(LDFLAGS)

TARGET = main

all: $(TARGET)

$(TARGET): $(GAM_OBJ_FILES) $(THR_OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

$(GAM_DIR)/$(OBJ_DIR)/%.o: $(GAM_DIR)/$(SRC_DIR)/%.cc $(GAM_INC_FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

$(THR_DIR)/$(OBJ_DIR)/%.o: $(THR_DIR)/$(SRC_DIR)/%.cc $(THR_INC_FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(GAM_DIR)/$(OBJ_DIR)/*.o $(THR_DIR)/$(OBJ_DIR)/*.o $(TARGET)
