#ifndef __OPEN_SONUX_H__
#define __OPEN_SONUX_H__

#include "http/Request.hpp"
#include "MiddlewareStack.hpp"
class OpenSonux final
{
public:
    OpenSonux(char **envp);
    ~OpenSonux();

    MiddlewareStack *getMiddlewareStack();

    void run();

private:
    Request *request;
    Response *response;
    MiddlewareStack *middlewareStack;
};

#endif
