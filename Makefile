# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
INCLUDE_DIR = include

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
APP_SRC = $(filter-out $(SRC_DIR)/main.cpp, $(SRC))  # Exclude main.cpp for tests
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
APP_OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(APP_SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC))

# Libraries
APP_LIBS = -lpthread -lcurl
TEST_LIBS = -lgtest -lgmock -lgmock_main -lpthread -lcurl

# Targets
EXEC = $(BUILD_DIR)/weather_app
TEST_EXEC = $(BUILD_DIR)/weather_test

# Default target
all: $(EXEC)

# Build the main application
$(EXEC): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(APP_LIBS)

# Build the test executable
$(TEST_EXEC): $(APP_OBJ) $(TEST_OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(TEST_LIBS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(INCLUDE_DIR)/*.h)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test source files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp $(wildcard $(INCLUDE_DIR)/*.h)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(TEST_EXEC)
	$(TEST_EXEC)

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)
