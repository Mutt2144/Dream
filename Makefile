GXX=g++
GXXFLAGS=-std=c++17
MAIN=src/main.cpp
INCLUDE=src/app/include/*.h
SOURCE=src/app/source/*.cpp
BUILD_DIR=build
LIBS=-lSDL2 -lSDL2_image -lGL

all: create_dirs
	clear
	$(GXX) $(GXXFLAGS) $(MAIN) $(SOURCE) -o $(BUILD_DIR)/main $(LIBS)

create_dirs:
	mkdir -p $(BUILD_DIR)