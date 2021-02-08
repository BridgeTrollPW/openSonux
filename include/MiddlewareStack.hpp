#ifndef MIDDLEWARESTACK_HPP
#define MIDDLEWARESTACK_HPP

#include <stack>

#include "MiddlewareInvocation.hpp"

class MiddlewareStack
{
public:
    MiddlewareStack(Request *request, Response *response);
    void push(MiddlewareInvocation *middleware);
    void execute();

private:
    std::stack<MiddlewareInvocation *> middlewares;
    Request *request;
    Response *response;
};

#endif