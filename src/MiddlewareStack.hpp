#ifndef __MIDDLEWARE_STACK_H__
#define __MIDDLEWARE_STACK_H__

#include <stack>
#include "contracts/MiddlewareInvocation.hpp"

class MiddlewareStack
{
public:
MiddlewareStack(Request &request, Response &response);
    void push(MiddlewareInvocation *middleware);
    void execute();

private:
    std::stack<MiddlewareInvocation *> middlewares;
    Request *request;
    Response *response;
};

#endif