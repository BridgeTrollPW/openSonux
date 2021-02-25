#include <arpa/inet.h> // defines in_addr structure
#include <cstddef>
#include <errno.h> //It defines macros for reporting and retrieving error conditions through error codes
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses
#include <stdio.h>      // standard input and output library
#include <stdlib.h>     // this includes functions regarding memory allocation
#include <string.h>     // contains string functions
#include <sys/socket.h> // for socket creation
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <time.h>   //contains various functions for manipulating date and time
#include <unistd.h> //contains various constants

int main() {
  time_t clock;
  char buffer[256];
  int n;
  char dataSending[1025]; // Actually this is called packet in Network
                          // Communication, which contain data and send through.
  int clintListn = 0, clintConnt = 0;
  struct sockaddr_in ipOfServer;
  clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket
  memset(&ipOfServer, '0', sizeof(ipOfServer));
  memset(dataSending, '0', sizeof(dataSending));
  ipOfServer.sin_family = AF_INET;
  ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
  ipOfServer.sin_port =
      htons(8000); // this is the port number of running server
  bind(clintListn, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer));
  listen(clintListn, 20);

  while (1) {
    printf("-------------------------------\n");
    printf("-------------------------------\n");
    printf("-------------------------------\n");
    printf("Waiting for connection\n");
    clintConnt = accept(clintListn, (struct sockaddr *)NULL, NULL);
    if (clintConnt < 0) {
      printf("ERROR on accept\n");
    }

    printf("New Client connected\n");

    bzero(buffer, 256);
    n = read(clintConnt, buffer, 255);
    if (n < 0) {
      printf("ERROR reading from socket\n");
    }
    printf("Here is the message: \n%s\n", buffer);

    const char *response = "HTTP/1.1 200 OK \r\nContent-Type: application/json \r\nContent-Length: 0 \r\n\r\n";
    n = write(clintConnt, response, strlen(response));
    if (n < 0) {
      printf("ERROR writing to socket\n");
    }

    close(clintConnt);
  }

  return 0;
}