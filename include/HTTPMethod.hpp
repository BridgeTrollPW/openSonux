#ifndef HTTPMETHOD_HPP
#define HTTPMETHOD_HPP
#include "Router.hpp"

enum HTTPMethod {
  POST,
  GET,
  PATCH,
  DELETE,
  OPTIONS,
  HEAD,
  PUT,
  TRACE,
  CONNECT
};
#endif