#include "EmbeddedServer.hpp"
#include "HttpSession.hpp"
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
  LOG(INFO) << "Starting EmbeddedServer";
  if (bind(clintListn, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer)) <
      0) {
    char log[30];
    snprintf(log, 30, "ERROR binding to socket %d::%s", errno,
             strerror(errno));
    LOG(ERROR) << log;
    return;
  }
  listen(clintListn, 20);
  while (1) {
    clintConnt = accept(clintListn, (struct sockaddr *)NULL, NULL);
    if (clintConnt < 0) {
      LOG(ERROR) << "ERROR on accept:" << errno << "::" << strerror(errno);
      continue;
    }
    connectionPool.push(std::async(std::launch::async, [&]() -> int {
      int n;
      bzero(buffer, 256);
      if (read(clintConnt, buffer, 255) == -1) {
        LOG(ERROR) << "ERROR on read: " << errno << "::" << strerror(errno);
        return HTTPSessionState::TCPSOCKET_SERVER_READ_ERROR;
      }
      std::string bufferString(buffer);
      HTTPSession httpSession(bufferString);

      const std::string response = httpSession.getResponse()->build();
      if (write(clintConnt, response.c_str(), response.size()) == -1) {
        LOG(ERROR) << "ERROR on write: " << errno << "::" << strerror(errno);
        return HTTPSessionState::TCPSOCKET_SERVER_WRITE_ERROR;
      }

      if (close(clintConnt) == -1) {
        LOG(ERROR) << "ERROR on close:" << errno << "::" << strerror(errno);
      }
      return HTTPSessionState::DONE;
    }));
  }
}