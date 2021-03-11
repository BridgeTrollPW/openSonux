#include "../include/HttpSession.hpp"

HTTPSession::HTTPSession(std::string &rawRequest) {
  id = generateSessionId(64);
  request = new Request(rawRequest);
  response = new Response();
  response->addHeader("Content-Type", "application/json");
  response->entity("[1,2,3,4,5,{\"test\": false}]");
}

const Response *HTTPSession::getResponse() const { return response; }

std::string HTTPSession::generateSessionId(std::size_t length) {
  const std::string CHARACTERS =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  std::random_device random_device;
  std::mt19937 generator(random_device());
  std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

  std::string random_string;

  for (std::size_t i = 0; i < length; ++i) {
    random_string += CHARACTERS[distribution(generator)];
  }

  return random_string;
}

std::string HTTPSession::getId() { return id; }