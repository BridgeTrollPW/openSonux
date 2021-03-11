#ifndef HTTPSESSION_HPP
#define HTTPSESSION_HPP
#include "Request.hpp"
#include "Response.hpp"
#include <random>
#include <string>
enum HTTPSessionState { STARTED, DONE, TCPSOCKET_SERVER_READ_ERROR, TCPSOCKET_SERVER_WRITE_ERROR };

class HTTPSession {
private:
  std::string id;
  Request *request;
  Response *response;

public:
  HTTPSession(std::string &rawRequest);
  const Response* getResponse() const;
  std::string generateSessionId(std::size_t length);
  std::string getId();
};
#endif
