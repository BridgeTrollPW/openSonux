#ifndef __MIDDLEWARE_INTERFACE_H__
#define __MIDDLEWARE_INTERFACE_H__

#include "../http/Request.hpp"
#include "../http/Response.hpp"

class MiddlewareInvocation
{
public:
    virtual void invoke(Request *request, Response *response) = 0;
    virtual ~MiddlewareInvocation(){};
};

#endif