#include "MiddlewareStack.hpp"

#include "easylogging++.h"

MiddlewareStack::MiddlewareStack(Request *request, Response *response)
{
    this->request = request;
    this->response = response;
}

void MiddlewareStack::push(MiddlewareInvocation *middleware)
{
    middlewares.push(middleware);
    LOG(TRACE) << "Added " << typeid(*middleware).name();
}

void MiddlewareStack::execute()
{
    while (!middlewares.empty())
    {
        MiddlewareInvocation *invocation = middlewares.top();
        LOG(TRACE) << "Execute " << typeid(*invocation).name();
        invocation->invoke(request, response);
        middlewares.pop();
        delete invocation;
    }
}