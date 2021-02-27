#ifndef SESSION_HPP
#define SESSION_HPP
#include "Request.hpp"
#include <random>
#include <string>
enum SessionState { STARTED, DONE };

class Session {
private:
  std::string id;
  Request *request;

public:
  Session(std::string &rawRequest) {
    id = generateSessionId(64);
    request = new Request(rawRequest);
  }
  std::string generateSessionId(std::size_t length) {
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
  std::string getId() { return id; }
};
#endif
