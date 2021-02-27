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
  Response() {
    this->headerList = std::make_unique<HeaderList>();
    this->statusCode = std::make_unique<ResponseStatus>(HTTPStatus::OK, "OK");
  }

  std::string *getHeader(const std::string &key) {
    return headerList->get(key);
  }

  void addHeader(const std::string &key, const std::string &value) {
    headerList->add(key, value);
  }

  Response *status(const std::unique_ptr<ResponseStatus> &code) {
    // avoid memory leak when replacing status code with new pointer ->
    // current statusCode will not be deleted and leaked since I have no pointer
    // left to that memory address
    this->statusCode.reset(code.get());
    return this;
  }

  Response *entity(const std::string &body) {
    this->body = body;
    return this;
  }

  std::string build() {
    std::string response;
    return response.append("Status: ")
        .append(std::to_string(statusCode->getCode()))
        .append(" ")
        .append(statusCode->getReasonPhrase())
        .append("\r\n")
        .append(headerList->build())
        .append("\r\n")
        .append(body);
  }
};

#endif