#ifndef EXAMPLEMIDDLEWARE_HPP
#define EXAMPLEMIDDLEWARE_HPP

#include <memory>

#include "MiddlewareInvocation.hpp"
#include "ResponseStatus.hpp"

class ExampleMiddleware : public MiddlewareInvocation
{
public:
    void invoke(Request *request, Response *response) override
    {
        if (request->getHeader("token") == nullptr || (*request->getHeader("token")).length() < 1)
        {
            LOG(WARNING) << "Token was not in the request";
            response->status(std::make_unique<ResponseStatus>(std::move(HTTPStatus::UNAUTHORIZED), "Unauthorized"))->entity("{\"message\": \"token is missing\"}");
            return;
        }
        
        LOG(DEBUG) << "my middleware is executed with token: " << *request->getHeader("token");
        response->entity(std::string("{\"token\": ").append(*request->getHeader("token")));
    }

    ~ExampleMiddleware() override
    {
        LOG(DEBUG) << "destroyed";
    }

    explicit ExampleMiddleware() = default;
    ExampleMiddleware(const ExampleMiddleware&) = delete;
    ExampleMiddleware(ExampleMiddleware&&) = delete;
    ExampleMiddleware& operator=(const ExampleMiddleware&) = delete;
    ExampleMiddleware& operator=(ExampleMiddleware&&) = delete;

};

#endif