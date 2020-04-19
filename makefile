CXX = clang++-10
CXXFLAGS = -Wall -Wextra -pedantic -std=c++2a -g -fsanitize=address -DELPP_NO_DEFAULT_LOG_FILE -DELPP_DEBUG_ERRORS
LDFLAGS =  -fsanitize=address

SRC = main.cpp \
src/HeaderList.cpp \
src/OpenSonux.cpp \
src/MiddlewareStack.cpp \
lib/easyloggingcpp/easylogging++.cpp

OBJ = $(subst .cpp,.o,$(SRC))
EXEC = openSonux.cgi

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

depend: .depend

.depend: $(SRC)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJ)

distclean: clean
	$(RM) *~ .depend

include .depend