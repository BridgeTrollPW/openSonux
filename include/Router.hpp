#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <list>
#include "HTTPMethod.hpp"
#include "RouteWrapper.hpp"

class Router final{
public:
  void add(const HTTPMethod &httpMethod, const std::string &path,
           std::function<void(Request *, Response *)> invocation);
  void add(RouteWrapper *route);

  ~Router();

private:
  std::list<RouteWrapper *> routes;
};

#endif
