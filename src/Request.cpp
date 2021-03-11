#include "../include/Request.hpp"

Request::Request(std::string &rawRequest) { parse(rawRequest); }

void Request::parse(std::string &rawRequest) {
  // TODO only allow N Headers
  size_t pos = 0;
  std::string headerline, key, value, delimiter = "\n\r";
  bool bStatusLine = false;
  while ((pos = rawRequest.find(delimiter)) != std::string::npos) {
    log.trace(rawRequest.c_str());
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