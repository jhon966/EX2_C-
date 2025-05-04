CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
INCLUDES = -I.

SRC = main.cpp SquareMat.cpp test_scalar.cpp test_plus.cpp test_onari.cpp test_doubleplus.cpp test_divide.cpp
OBJ = $(SRC:.cpp=.o)
BIN = Main

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

Main: $(BIN)

test: $(BIN)
	./$(BIN)

valgrind: $(BIN)
	valgrind --leak-check=full ./$(BIN)

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all test valgrind clean Main
