#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <memory>
#include <string>

#include "HeaderList.hpp"
#include "ResponseStatus.hpp"

// https://tools.ietf.org/html/rfc3875#section-6
class Response {
private:
  std::unique_ptr<HeaderList> headerList;
  std::string body;
  std::unique_ptr<ResponseStatus> statusCode;

public:
  Response();
  std::string *getHeader(const std::string &key);
  void addHeader(const std::string &key, const std::string &value);
  Response *status(const std::unique_ptr<ResponseStatus> &code);
  Response *entity(const std::string &body);
  const std::string build() const;
};

#endif