#ifndef ROUTEWRAPPER_HPP
#define ROUTEWRAPPER_HPP

#include <functional>
#include <string>

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