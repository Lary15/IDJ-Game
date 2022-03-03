CC          = g++
LD          = g++ 
CFLAG       = -Wall
PROG_NAME   = main

SRC_DIR	    = ./src
OBJ_DIR   	= ./obj
BIN_DIR     = ./bin
SRC_LIST = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_LIST = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_LIST))

INCLUDE_DIRS = /usr/include/SDL2
LIBRARIES = SDL2 SDL2_image SDL2_mixer SDL2_ttf

CPPFLAGS += $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))
LDLIBS += $(foreach library,$(LIBRARIES),-l$(library))

.PHONY: all clean $(PROG_NAME) compile

all: $(PROG_NAME)

$(PROG_NAME): $(OBJ_DIR)/$(PROG_NAME).o $(OBJ_LIST) 
	$(LD) $^ -o $(BIN_DIR)/$@ $(LDLIBS)

$(OBJ_DIR)/$(PROG_NAME).o: 
	$(CC) $(PROG_NAME).cpp -g -c -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAG) $(CPPFLAGS)  -g -c -o $@ $<

clean:
	rm -f $(BIN_DIR)/$(PROG_NAME) $(OBJ_DIR)/*.o