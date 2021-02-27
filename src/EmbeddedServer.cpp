#include "EmbeddedServer.hpp"
#include "Session.hpp"
#include "easylogging++.h"
#include <cstdio>
#include <future>

EmbeddedServer::EmbeddedServer() {
  buffer = new char[256];
  clintListn = socket(AF_INET, SOCK_STREAM, 0);
  memset(&ipOfServer, '0', sizeof(ipOfServer));
  ipOfServer.sin_family = AF_INET;
  ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
  ipOfServer.sin_port = htons(8000);
}

void EmbeddedServer::start() {
  LOG(INFO) << "Starting EmbeddedServer";
  if (bind(clintListn, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer)) <
      0) {
    char log[30];
    snprintf(log, 30, "ERROR binding to socket %d\n", errno);
    LOG(ERROR) << log;
    return;
  }
  listen(clintListn, 20);
  while (1) {
    LOG(TRACE) << "Waiting for connection\n";
    clintConnt = accept(clintListn, (struct sockaddr *)NULL, NULL);

    connectionPool.push(std::async(std::launch::async, [&]() -> int {
      int n;
      bzero(buffer, 256);
      n = read(clintConnt, buffer, 255);
      std::string bufferString(buffer);
      Session session(bufferString);
      
      LOG(TRACE) << "[" << session.getId() << "]"
                 << "Handling async client request";
      
      if (clintConnt < 0) {
        LOG(ERROR) << "[" << session.getId() << "]"
                   << "ERROR on accept";
      }

      if (n < 0) {
        LOG(ERROR) << "[" << session.getId() << "]"
                   << "ERROR reading from socket";
      }

      const char *response =
          "HTTP/1.1 200 OK \r\nContent-Type: application/json "
          "\r\nContent-Length: 0 \r\n\r\n";
      n = write(clintConnt, response, strlen(response));
      if (n < 0) {
        printf("ERROR writing to socket %d\n", errno);
      }

      close(clintConnt);
      LOG(TRACE) << "[" << session.getId() << "]"
                 << "Client connection closed";
      return SessionState::DONE;
    }));
  }
}