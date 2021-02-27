#ifndef EMBEDDEDSERVER_HPP
#define EMBEDDEDSERVER_HPP

#include <arpa/inet.h> // defines in_addr structure
#include <cerrno> //It defines macros for reporting and retrieving error conditions through error codes
#include <cstddef>
#include <cstdio>  // standard input and output library
#include <cstdlib> // this includes functions regarding memory allocation
#include <cstring> // contains string functions
#include <ctime>   //contains various functions for manipulating date and time
#include <future>
#include <map>
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses
#include <queue>
#include <string>       // contains string functions
#include <sys/socket.h> // for socket creation
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <unistd.h>    //contains various constants

class EmbeddedServer {
private:
  char *buffer;
  int clintListn = 0, clintConnt = 0;
  struct sockaddr_in ipOfServer;
  std::queue<std::future<int>> connectionPool;

public:
  EmbeddedServer();
  void start();
};

#endif