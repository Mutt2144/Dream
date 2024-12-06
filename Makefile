GXX=g++
GXXFLAGS=-std=c++17
MAIN=src/main.cpp
SRCS=""
BUILD_DIR=build

all: create_dirs
	clear
	$(GXX) $(GXXFLAGS) $(MAIN) -o $(BUILD_DIR)/main

create_dirs:
	mkdir -p $(BUILD_DIR)