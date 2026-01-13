# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wpedantic -Wextra -std=c99 -Iinclude -MMD -MP
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin

# Target
TARGET  = arrpeegee

# Source, object, and dependency files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $(BIN_DIR)/$(TARGET) $(LDFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Include auto-generated header dependencies
-include $(DEPS)

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TARGET)

run: all
	./$(BIN_DIR)/$(TARGET)

.PHONY: all clean

