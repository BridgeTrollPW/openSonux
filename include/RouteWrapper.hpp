#ifndef ROUTEWRAPPER_HPP
#define ROUTEWRAPPER_HPP

#include <functional>
#include <string>

#include "HTTPMethod.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Router.hpp"


class RouteWrapper
{
private:
    HTTPMethod httpMethod;
    std::string path;
    std::function<void(Request *, Response *)> invocation;

public:
    RouteWrapper(const HTTPMethod &_httpMethod, const std::string &_path, const std::function<void(Request *, Response *)> &_invocation)
        : httpMethod(std::move(_httpMethod)), path(std::move(_path)), invocation(std::move(_invocation)) {}
};

#endif