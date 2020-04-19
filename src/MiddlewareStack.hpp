#ifndef __MIDDLEWARE_STACK_H__
#define __MIDDLEWARE_STACK_H__

#include <stack>
#include "contracts/MiddlewareInvocation.hpp"

class MiddlewareStack
{
public:
    static MiddlewareStack &getInstance();
    MiddlewareStack(MiddlewareStack const&) = delete;
    void operator=(MiddlewareStack const&)  = delete;

    void push(MiddlewareInvocation *middleware);
    void execute();

private:
    MiddlewareStack() {}

    std::stack<MiddlewareInvocation *> middlewares;
};

#endif