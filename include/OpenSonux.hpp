#ifndef OPENSONUX_HPP
#define OPENSONUX_HPP

#include "MiddlewareStack.hpp"
#include "Request.hpp"
#include "Router.hpp"

/**
 * @brief 
 * 
 */
class OpenSonux final
{
public:
    explicit OpenSonux(char **envp);
    ~OpenSonux();

    MiddlewareStack *getMiddlewareStack();

    void run();

private:
    Request *request;
    Response *response;
    MiddlewareStack *middlewareStack;
    Router *router;
};

#endif
