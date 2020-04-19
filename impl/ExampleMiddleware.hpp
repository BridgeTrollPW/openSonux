#ifndef __EXAMPLE_MIDDLEWARE_H__
#define __EXAMPLE_MIDDLEWARE_H__

#include "../src/contracts/MiddlewareInvocation.hpp"

class ExampleMiddleware : MiddlewareInvocation
{
public:
    void invoke(Request *request, Response *response) {}
};

#endif