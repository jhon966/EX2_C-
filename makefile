CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

OBJ = main.o SquareMat.o test_scalar.o test_plus.o test_onari.o test_doubleplus.o test_divide.o
TARGET = Main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp SquareMat.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Main: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all Main test valgrind clean
