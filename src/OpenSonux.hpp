#ifndef __OPEN_SONUX_H__
#define __OPEN_SONUX_H__

#include "http/Request.hpp"

class OpenSonux final
{
public:
    OpenSonux(char **envp);
    ~OpenSonux();

    void run();

private:
    Request *request;
};

#endif
