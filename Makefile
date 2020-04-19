CXX = clang++-10
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++20 -g -fsanitize=address -fconcepts-ts
LDFLAGS =  -fsanitize=address

SRC = main.cpp src/HeaderProcessor.cpp
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)