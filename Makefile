
SRC_DIR := src
INCLUDE_DIR := $(SRC_DIR)/include

# List all the .cpp files in the src directory
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# List all the .hpp files in the include directory
HPP_FILES := $(wildcard $(INCLUDE_DIR)/*.hpp)

all:
	g++ -I $(INCLUDE_DIR) -L $(SRC_DIR)/lib -o main $(CPP_FILES) -lmingw32 -lSDL2main -lSDL2
