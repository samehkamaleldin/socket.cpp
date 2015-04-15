# =============================================================================================
# PROJECT: socket-cpp
# MODULE : Makefile
# SUMMARY: Project build file that define build targets and steps
# =============================================================================================

# Library binary information
LIB_NAME     = socket.cpp
LIB_VER_MAJ  = 0
LIB_VER_MIN  = 0
LIB_VER_BLD  = 1
LIB_VERSION  = $(LIB_VER_MAJ).$(LIB_VER_MIN).$(LIB_VER_BLD)

LIB_HOME_DIR = ..
LIB_SRC_DIR  = $(LIB_HOME_DIR)/src
LIB_DIST_DIR = $(LIB_HOME_DIR)/dist
LIB_INC_DIR  = $(LIB_HOME_DIR)/src
EXAMPLES_DIR = $(LIB_HOME_DIR)/example

# Set of src/inc files used in build process
INC_FILES   = $(wildcard $(LIB_SRC_DIR)/**/*.hpp) $(wildcard $(LIB_SRC_DIR)/*.hpp)
SRC_FILES   = $(wildcard $(LIB_SRC_DIR)/**/*.cpp) $(wildcard $(LIB_SRC_DIR)/*.cpp)
OBJ_FILES   = $(patsubst %.cpp,%.o, $(SRC_FILES))

# Compiler/Linker required information
TARGET   = libsocket.cpp.so.$(LIB_VER_MAJ).$(LIB_VER_MIN).$(LIB_VER_BLD)
CXX      = g++
CXXFLAGS = -g -I$(LIB_INC_DIR)
LDFLAGS  = -shared -fpic

default: all

all: $(TARGET) examples

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(LIB_DIST_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_FILES) -o $(LIB_DIST_DIR)/$(TARGET) $(LDFLAGS)

examples:
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(EXAMPLES_DIR)/demo_tcp_server.cpp -o $(LIB_DIST_DIR)/demo_tcp_server.out
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(EXAMPLES_DIR)/demo_tcp_client.cpp -o $(LIB_DIST_DIR)/demo_tcp_client.out

headers:
	@mkdir -p $(LIB_DIST_DIR)/include
	@cp -r $(LIB_INC_DIR)/* $(LIB_DIST_DIR)/include/
	@rm --recursive --force $(LIB_DIST_DIR)/include/**/*.cpp
	@rm --recursive --force $(LIB_DIST_DIR)/include/**/*.o

package: all headers
	@mkdir -p $(LIB_DIST_DIR)/examples
	@cp $(EXAMPLES_DIR)/* $(LIB_DIST_DIR)/examples
	@tar -cvzf $(LIB_DIST_DIR)/$(LIB_NAME)-$(LIB_VERSION).tar.gz --directory=$(LIB_DIST_DIR) $(LIB_HOME_DIR)/LICENSE \
																																					 $(TARGET) \
																																					 include   \
																																					 examples

clean:
	@rm --recursive --force $(OBJ_FILES)
	@rm --recursive --force $(LIB_DIST_DIR)/$(TARGET)
	@rm --recursive --force $(LIB_DIST_DIR)/include
	@rm --recursive --force $(LIB_DIST_DIR)/examples
	@rm --recursive --force $(LIB_DIST_DIR)/demo_tcp_server.out
	@rm --recursive --force $(LIB_DIST_DIR)/demo_tcp_client.out
	@rm --recursive --force $(LIB_DIST_DIR)/*.tar*
