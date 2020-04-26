#ifndef __EXAMPLE_MIDDLEWARE_H__
#define __EXAMPLE_MIDDLEWARE_H__

#include "MiddlewareInvocation.hpp"
#include "Status.hpp"

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
        response->entity(std::string("{\"token\": ").append(*request->getHeader("token")));
    }

    ~ExampleMiddleware()
    {
        LOG(DEBUG) << "destroyed";
    }
};

#endif