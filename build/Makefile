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
TARGET   = socket-cpp.so
CXX      = g++
CXXFLAGS = -g -I$(LIB_INC_DIR)
LDFLAGS  = -shared -fpic

default: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(LIB_DIST_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_FILES) -o $(LIB_DIST_DIR)/$(TARGET) $(LDFLAGS)

examples:
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(EXAMPLES_DIR)/demo_tcp_server.cpp -o $(LIB_DIST_DIR)/demo_tcp_server.out
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(EXAMPLES_DIR)/demo_tcp_client.cpp -o $(LIB_DIST_DIR)/demo_tcp_client.out
