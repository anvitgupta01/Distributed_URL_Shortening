# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Directories
SRC_DIR = .
OBJ_DIR = obj

# Source files
SRC = $(SRC_DIR)/URLShortnerAndRedirection.cpp $(SRC_DIR)/HashFunction.cpp

# Object files (compiled source files)
OBJ = $(OBJ_DIR)/URLShortnerAndRedirection.o $(OBJ_DIR)/HashFunction.o

# Output executable
TARGET = URLShortnerAndRedirection

# Default target
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile .cc files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)  # Ensure obj directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the program after building
run: $(TARGET)
	./$(TARGET)