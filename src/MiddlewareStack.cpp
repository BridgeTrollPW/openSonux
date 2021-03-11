#include "../include/MiddlewareStack.hpp"

MiddlewareStack::MiddlewareStack(Request *request, Response *response)
{
    this->request = request;
    this->response = response;
}

void MiddlewareStack::push(MiddlewareInvocation *middleware)
{
    middlewares.push(middleware);
    log.trace("Added %s to middleware stack",  typeid(*middleware).name());
}

void MiddlewareStack::execute()
{
    while (!middlewares.empty())
    {
        MiddlewareInvocation *invocation = middlewares.top();
        log.trace("Execute and pop %s",  typeid(*invocation).name());
        invocation->invoke(request, response);
        middlewares.pop();
        delete invocation;
    }
}