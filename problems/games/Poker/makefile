print-%: ; @echo $*=$($*)

CC := i686-w64-mingw32-g++ # Compiler for Windows MinGW64
# CC := clang --analyze # and comment out the linker last line for sanity

ASSETS_DIR := assets
BIN_DIR := bin
BUILD_DIR := build
LIB_DIR := lib
SRC_DIR := src
INC_DIR := inc

PROJECT_TARGET := $(BUILD_DIR)/main

PROJECT_MAIN_OBJECT := $(BUILD_DIR)/main.o

SRC_EXT := cpp
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SOURCES:.$(SRC_EXT)=.o))

CFLAGS := -g -Wall -std=c++0x
LDFLAGS := # --verbose

LIB := \
	-L $(LIB_DIR) \
	-L $(BIN_DIR) \

INC := \
	-I $(SRC_DIR) \
	-I $(INC_DIR) \

$(PROJECT_TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) $(LDFLAGS) $^ $(LIB) -o $(PROJECT_TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

all: $(PROJECT_TARGET)

clean:
	@echo "Cleaning...";
	$(RM) -r $(BUILD_DIR) $(PROJECT_TARGET)

run: all
	$(PROJECT_TARGET)

.PHONY: all clean run
