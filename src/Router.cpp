#include "../include/Router.hpp"
#include <functional>

void Router::add(const HTTPMethod &httpMethod, const std::string &path, std::function<void(Request *, Response *)> invocation)
{
    routes.push_back(new RouteWrapper(httpMethod, path, invocation));
}

void Router::add(RouteWrapper* route)
{
    routes.push_back(route);
}

Router::~Router()
{
    //cleanup pointers to routes
    routes.remove_if([](RouteWrapper *route) -> bool { delete route; return true; });
}