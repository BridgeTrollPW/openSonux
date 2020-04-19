#ifndef __EXAMPLE_MIDDLEWARE_H__
#define __EXAMPLE_MIDDLEWARE_H__

#include "../src/contracts/MiddlewareInvocation.hpp"
#include "../lib/easyloggingcpp/easylogging++.h"

class ExampleMiddleware : public MiddlewareInvocation
{
public:
    void invoke(Request *request, Response *response)
    {
        LOG(DEBUG) << "my middleware is executed";
    }

    ~ExampleMiddleware()
    {
        LOG(DEBUG) << "destroyed";
    }
};

#endif