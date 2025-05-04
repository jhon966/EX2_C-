CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# All source files for Main
SOURCES = main.cpp SquareMat.cpp test_plus.cpp test_divide.cpp test_doubleplus.cpp test_onari.cpp test_scalar.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
Main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Main $(OBJECTS)

# Generic rule to compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run valgrind on Main
valgrind: Main
	valgrind ./Main

# Clean all build artifacts
clean:
	rm -f *.o Main
