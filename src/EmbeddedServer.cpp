#include "../include/EmbeddedServer.hpp"
#include "../include/HttpSession.hpp"
#include <cerrno>
#include <cstdio>
#include <cstring>
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
  log.info("Starting EmbeddedServer");
  if (bind(clintListn, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer)) <
      0) {
    log.error("ERROR binding to socket %d::%s", errno, strerror(errno));
    return;
  }
  listen(clintListn, 20);
  while (1) {
    clintConnt = accept(clintListn, (struct sockaddr *)NULL, NULL);
    if (clintConnt < 0) {
      log.error("ERROR on accept: %d::%s", errno, strerror(errno));
      continue;
    }
    connectionPool.push(std::async(std::launch::async, [&]() -> int {
      int n;
      bzero(buffer, 256);
      if (read(clintConnt, buffer, 255) == -1) {
        log.error("ERROR on read: %d::%s", errno, strerror(errno));
        return HTTPSessionState::TCPSOCKET_SERVER_READ_ERROR;
      }
      std::string bufferString(buffer);
      HTTPSession httpSession(bufferString);

      const std::string response = httpSession.getResponse()->build();
      if (write(clintConnt, response.c_str(), response.size()) == -1) {
        log.error("ERROR on write: %d::%s", errno, strerror(errno));
        return HTTPSessionState::TCPSOCKET_SERVER_WRITE_ERROR;
      }

      if (close(clintConnt) == -1) {
        log.error("ERROR on close: %d::%s", errno, strerror(errno));
      }
      return HTTPSessionState::DONE;
    }));
  }
}