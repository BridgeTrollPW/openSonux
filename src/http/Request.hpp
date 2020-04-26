#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <string>
#include <iostream>
#include <algorithm>

#include "HeaderList.hpp"
#include "easylogging++.h"

class Request
{
public:
    Request(char **envp, const std::string& _body) : body(_body)
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
    const std::string body;
};

#endif