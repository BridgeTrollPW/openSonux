#ifndef __ROUTE_WRAPPER_H__
#define __ROUTE_WRAPPER_H__

#include <string>
#include <functional>
#include "Request.hpp"
#include "Response.hpp"

class RouteWrapper
{
private:
    std::string httpMethod;
    std::string path;
    std::function<void(Request *, Response *)> invocation;

public:
    RouteWrapper(const std::string &_httpMethod, const std::string &_path, std::function<void(Request *, Response *)> _invocation)
        : httpMethod(_httpMethod), path(_path), invocation(_invocation) {}
};

#endif