#include "OpenSonux.hpp"

#include "MiddlewareStack.hpp"
#include "../lib/easyloggingcpp/easylogging++.h"

OpenSonux::OpenSonux(char **envp)
{
    LOG(DEBUG) << "Starting OpenSonux";
    request = new Request(envp);
}
OpenSonux::~OpenSonux()
{
    delete request;
}

void OpenSonux::run()
{
    MiddlewareStack::getInstance().execute();
}