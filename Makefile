TARGET = bfi
BUILD_DIR = build
SRC_DIR = src

LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: all

all: $(BUILD_DIR)/$(TARGET)

# Find all source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Generate corresponding object file paths
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

# Find all headers
HEADERS = $(wildcard $(SRC_DIR)/*.h)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(BUILD_DIR)/$(TARGET) $(OBJECTS)

# Link object files into executable
$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)
