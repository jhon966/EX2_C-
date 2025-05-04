CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

SRC = SquareMat.cpp
HEADERS = SquareMat.h

MAIN = main.cpp
TESTS = test_divide.cpp test_plus.cpp test_doubleplus.cpp test_onari.cpp test_scalar.cpp

OBJS = $(SRC:.cpp=.o)
TEST_OBJS = $(TESTS:.cpp=.o)

TARGET_MAIN = Main

.PHONY: all clean valgrind

all: $(TARGET_MAIN)

$(TARGET_MAIN): $(OBJS) $(TEST_OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: $(TARGET_MAIN)
	valgrind --leak-check=full ./$(TARGET_MAIN)

clean:
	rm -f *.o $(TARGET_MAIN)
