#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <memory>

#include "OpenSonux.hpp"
#include "ExampleMiddleware.hpp"

class Application
{
public:
    Application(char **envp)
    {
        OpenSonux openSonux{envp};
        openSonux.getMiddlewareStack()->push(new ExampleMiddleware());
        openSonux.run();
    }
};

#endif