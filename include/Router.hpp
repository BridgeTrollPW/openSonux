#ifndef __ROUTER_H__
#define __ROUTER_H__

#include "RouteWrapper.hpp"
#include <list>

class Router
{
public:
    const std::string POST{"POST"};
    const std::string GET{"GET"};
    const std::string PATCH{"PATCH"};
    const std::string DELETE{"DELETE"};
    const std::string OPTIONS{"OPTIONS"};
    const std::string HEAD{"HEAD"};
    const std::string PUT{"PUT"};
    const std::string TRACE{"TRACE"};
    const std::string CONNECT{"CONNECT"};

    void add(const std::string &httpMethod, const std::string &path, std::function<void(Request*, Response*)> invocation);
    void add(RouteWrapper* route);

    ~Router();
private:
    std::list<RouteWrapper*> routes;
};

#endif
