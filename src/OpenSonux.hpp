#ifndef __OPEN_SONUX_H__
#define __OPEN_SONUX_H__

#include "HeaderList.hpp"
#include "MiddlewareStack.hpp"
#include <iostream>

class OpenSonux final
{
private:
    HeaderList *headerList;

public:
    OpenSonux(char **envp);
    ~OpenSonux();

    void run();
};

#endif
