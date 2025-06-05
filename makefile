CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I./ -ISFML/include
LDFLAGS  = -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = Main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

main: all
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
valgrind: all
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)