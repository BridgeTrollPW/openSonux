#ifndef __OPEN_SONUX_H__
#define __OPEN_SONUX_H__

#include "HeaderProcessor.hpp"

class OpenSonux final
{
private:
    HeaderProcessor *headers;

public:
    OpenSonux(char **envp)
    {
        headers = new HeaderProcessor(envp);
    }
    ~OpenSonux()
    {
        delete headers;
    }

    void run();

    HeaderProcessor *getHeaders() const {
        return headers;
    };
};

#endif
