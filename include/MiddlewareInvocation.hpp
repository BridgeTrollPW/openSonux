#ifndef MIDDLEWAREINTERFACE_HPP
#define MIDDLEWAREINTERFACE_HPP

#include "Request.hpp"
#include "Response.hpp"

class MiddlewareInvocation
{
public:
    virtual void invoke(Request *request, Response *response) = 0;
    virtual ~MiddlewareInvocation(){};
};

#endif