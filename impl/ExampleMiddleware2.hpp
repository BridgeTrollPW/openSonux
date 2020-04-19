#ifndef __EXAMPLE_MIDDLEWARE_2_H__
#define __EXAMPLE_MIDDLEWARE_2_H__

#include "../src/contracts/MiddlewareInvocation.hpp"
#include "../lib/easyloggingcpp/easylogging++.h"

class ExampleMiddleware2 : public MiddlewareInvocation
{
public:
    void invoke(Request *request, Response *response)
    {
        LOG(DEBUG) << "my middleware is executed";
    }

    ~ExampleMiddleware2()
    {
        LOG(DEBUG) << "sadsadsad destroyed";
    }
};

#endif