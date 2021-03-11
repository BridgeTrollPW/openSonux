#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <string>

#include "HTTPMethod.hpp"
#include "HeaderList.hpp"
#include "Logger.hpp"

struct Header {
  const std::string header;
  const std::string value;
  Header(const std::string &_header, const std::string &_value)
      : header(_header), value(_value) {}
};

class Request final {
public:
  Request(std::string &rawRequest);

private:
  std::list<Header *> headers;
  const std::string body;
  void parse(std::string &rawRequest);
  Logger log{"Request"};
};

#endif