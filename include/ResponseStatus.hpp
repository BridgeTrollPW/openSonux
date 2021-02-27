#ifndef RESPONSESTATUS_HPP
#define RESPONSESTATUS_HPP

#include <string>

enum HTTPStatus { OK = 200, UNAUTHORIZED = 401 };

class ResponseStatus {
private:
  const HTTPStatus code;
  const std::string reasonPhrase;

public:
  ResponseStatus(HTTPStatus _code, std::string _reasonPhrase)
      : code(_code), reasonPhrase(std::move(_reasonPhrase)) {}
  [[nodiscard]] HTTPStatus getCode() const { return code; }
  [[nodiscard]] std::string getReasonPhrase() const { return reasonPhrase; }
};

#endif