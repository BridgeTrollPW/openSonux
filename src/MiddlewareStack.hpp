#ifndef __MIDDLEWARE_STACK_H__
#define __MIDDLEWARE_STACK_H__

#include <stack>
#include "contracts/MiddlewareInvocation.hpp"

class MiddlewareStack
{
public:
    MiddlewareStack register(MiddlewareInvocation *middleware)
    {
        middlewares.push(middleware);
    }

    void execute()
    {
        while (!middlewares.empty())
        {
            middleware.top()->invoke(nullptr, nullptr);
            middleware.pop();
        }
    }

private:
    std::stack<MiddlewareInvocation *> middlewares;
};

#endif