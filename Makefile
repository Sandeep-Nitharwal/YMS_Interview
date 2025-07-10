CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS := -L.
LDLIBS := -lfib

SRC_DIR := src
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main executable
TARGET := fib_program

# Library files
LIB_STATIC := libfib.a
LIB_SHARED := libfib.so

.PHONY: all clean

all: $(LIB_STATIC) $(LIB_SHARED) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Static library
$(LIB_STATIC): $(BUILD_DIR)/fib.o
	ar rcs $@ $^

# Shared library
$(LIB_SHARED): $(BUILD_DIR)/fib.o
	$(CXX) -shared -o $@ $^

# Main program
$(TARGET): $(BUILD_DIR)/main.o $(LIB_STATIC)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(LIB_STATIC) $(LIB_SHARED)

run: $(TARGET)
	./$(TARGET)