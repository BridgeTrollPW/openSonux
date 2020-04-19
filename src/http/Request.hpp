#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <string>

#include "../HeaderList.hpp"

class Request
{
public:
    Request(char **envp)
    {
        headerList = new HeaderList(envp);
    }

    ~Request()
    {
        delete headerList;
    }

    std::string *getHeader(const std::string &key)
    {
        return headerList->get(key);
    }

private:
    HeaderList *headerList;
};

#endif