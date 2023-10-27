CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror
CXXOPT := -O3
CXXSTD := -std=c++17
INCLUDES := -I include

CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)
LDFLAGS :=

SRC_DIR := src
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.cxx)
OBJS := $(patsubst $(SRC_DIR)/%.cxx, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: main

OBJS += $(BUILD_DIR)/cleanup_data.o

main: main.cxx $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cxx
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -v $(BUILD_DIR)/*.o main