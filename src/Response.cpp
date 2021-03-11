#include "../include/Response.hpp"

Response::Response() {
  this->headerList = std::make_unique<HeaderList>();
  this->statusCode = std::make_unique<ResponseStatus>(HTTPStatus::OK, "OK");
}

std::string *Response::getHeader(const std::string &key) {
  return headerList->get(key);
}

void Response::addHeader(const std::string &key, const std::string &value) {
  headerList->add(key, value);
}

Response *Response::status(const std::unique_ptr<ResponseStatus> &code) {
  // avoid memory leak when replacing status code with new pointer ->
  // current statusCode will not be deleted and leaked since I have no pointer
  // left to that memory address
  this->statusCode.reset(code.get());
  return this;
}

Response *Response::entity(const std::string &body) {
  this->body = body;
  this->addHeader("Content-Length", std::to_string(body.size()));
  return this;
}

const std::string Response::build() const {
  std::string httpResponse;
  httpResponse.append("HTTP/1.1 ")
      .append(std::to_string(statusCode->getCode()))
      .append(" ")
      .append(statusCode->getReasonPhrase())
      .append("\r\n")
      .append(headerList->build())
      .append("\r\n")
      .append(body);
  return httpResponse;
}