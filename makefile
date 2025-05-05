# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Source files (add more .cpp files if needed)
SRCS = main.cpp SquareMat.cpp test_plus.cpp test_scalar.cpp test_onari.cpp test_doubleplus.cpp test_divide.cpp SquareMat.cpp
OBJS = $(SRCS:.cpp=.o)

# Output binary
TARGET = main

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
Main: $(TARGET)
	./$(TARGET)
# Run the program
test: $(TARGET)
	./$(TARGET)
# Run the program with valgrind
valgrind: $(TARGET)
	ulimit -n 1024; valgrind --leak-check=full ./$(TARGET)
# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)