#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

#include "HeaderList.hpp"
#include "easylogging++.h"

class Request
{
public:
    Request(char **envp, std::string _body) : body(std::move(_body))
    {
        headerList = std::make_unique<HeaderList>(envp);
    }

    std::string *getHeader(const std::string &key)
    {
        return headerList->get(key);
    }

private:
    std::unique_ptr<HeaderList> headerList;
    const std::string body;
};

#endif