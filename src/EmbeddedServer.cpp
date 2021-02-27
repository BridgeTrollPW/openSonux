#include "EmbeddedServer.hpp"

EmbeddedServer::EmbeddedServer() {
  clintListn = socket(AF_INET, SOCK_STREAM, 0);
  memset(&ipOfServer, '0', sizeof(ipOfServer));
  ipOfServer.sin_family = AF_INET;
  ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
  ipOfServer.sin_port = htons(8000);
}

void EmbeddedServer::start() {

  if (bind(clintListn, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer)) < 0) {
    printf("ERROR binding to socket %d\n", errno);
    return;
  }
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

    const char *response = "HTTP/1.1 200 OK \r\nContent-Type: application/json "
                           "\r\nContent-Length: 0 \r\n\r\n";
    n = write(clintConnt, response, strlen(response));
    if (n < 0) {
     printf("ERROR writing to socket %d\n", errno);
    }

    close(clintConnt);
  }
}