#include "OpenSonux.hpp"

#include "MiddlewareStack.hpp"
#include "../lib/easyloggingcpp/easylogging++.h"

OpenSonux::OpenSonux(char **envp)
{
    LOG(DEBUG) << "Starting OpenSonux";
    request = new Request(envp);
    response = new Response();
    middlewareStack = new MiddlewareStack(request, response);
}

OpenSonux::~OpenSonux()
{
    delete request;
    delete response;
    delete middlewareStack;
}

void OpenSonux::run()
{
    middlewareStack->execute();
    std::cout << response->build();
}

MiddlewareStack *OpenSonux::getMiddlewareStack()
{
    return middlewareStack;
}