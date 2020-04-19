CXX = clang++-10
CXXFLAGS = -Wall -Wextra -pedantic -std=c++2a -g -fsanitize=address -DELPP_NO_DEFAULT_LOG_FILE -DELPP_DEBUG_ERRORS
LDFLAGS =  -fsanitize=address

SRC = main.cpp \
src/HeaderList.cpp \
src/OpenSonux.cpp \
src/MiddlewareStack.cpp \
lib/easyloggingcpp/easylogging++.cpp

OBJ = $(SRC:.cpp=.o)
EXEC = openSonux.cgi

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)