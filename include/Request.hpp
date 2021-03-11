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

struct Header {
  const std::string header;
  const std::string value;
  Header(const std::string &_header, const std::string &_value)
      : header(_header), value(_value) {}
};

class Request final {
public:
  Request(std::string &rawRequest) { parse(rawRequest); }

private:
  std::list<Header *> headers;
  const std::string body;

  void parse(std::string &rawRequest) {
    // TODO only allow N Headers
    size_t pos = 0;
    std::string headerline, key, value, delimiter = "\n\r";
    bool bStatusLine = false;
    while ((pos = rawRequest.find(delimiter)) != std::string::npos) {
      LOG(DEBUG) << rawRequest;
      if (!bStatusLine) {
        headerline = rawRequest.substr(0, pos);
        rawRequest.erase(0, pos + delimiter.length());
        bStatusLine = true;
      } else {
        headerline = rawRequest.substr(0, pos);
        size_t posLine = headerline.find(":");
        value = headerline.substr(0, posLine);
        key = headerline.substr(posLine, rawRequest.size());
        headers.emplace_back(
            new Header{rawRequest.substr(0, pos),
                       rawRequest.substr(pos, rawRequest.size())});
        rawRequest.erase(0, pos + delimiter.length());
      }
    }
  }
};

#endif