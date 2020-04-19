#ifndef __EXAMPLE_MIDDLEWARE_H__
#define __EXAMPLE_MIDDLEWARE_H__

#include "src/contracts/MiddlewareInvocation.hpp"
#include "lib/easyloggingcpp/easylogging++.h"
#include "src/http/Status.hpp"

class ExampleMiddleware : public MiddlewareInvocation
{
public:
    void invoke(Request *request, Response *response)
    {
        if (request->getHeader("token") == nullptr || (*request->getHeader("token")).length() < 1)
        {
            LOG(WARNING) << "Token was not in the request";
            response->status(new http::Status(401, "Unauthorized"))->entity("{\"message\": \"token is missing\"}");
            return;
        }
        
        LOG(DEBUG) << "my middleware is executed with token: " << *request->getHeader("token");
        response->entity("{test}");
    }

    ~ExampleMiddleware()
    {
        LOG(DEBUG) << "destroyed";
    }
};

#endif