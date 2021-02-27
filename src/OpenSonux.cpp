#include "OpenSonux.hpp"

#include "EmbeddedServer.hpp"
#include "MiddlewareStack.hpp"
#include "easylogging++.h"

OpenSonux::OpenSonux(char **envp)
{
    LOG(TRACE) << "Starting OpenSonux";
    EmbeddedServer embeddedServer;
    embeddedServer.start();
    std::string body;
    if (getenv("CONTENT_LENGTH") != nullptr)
    {
        char Buffer[512] = {0};
        int InputLength = atoi(getenv("CONTENT_LENGTH"));
        InputLength = std::min((unsigned long)InputLength, sizeof(Buffer) - 1); /* Avoid buffer overflow */
        fread(Buffer, InputLength, 1, stdin);
        body = Buffer;
    }
    else
    {
        LOG(TRACE) << "Body is empty";
    }
    request = new Request(envp, body);
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