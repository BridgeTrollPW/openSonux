#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <string>
#include <iostream>

#include "../HeaderList.hpp"
#include "../../lib/easyloggingcpp/easylogging++.h"

class Request
{
public:
    Request(char **envp)
    {
        headerList = new HeaderList(envp);
        if (headerList->get("CONTENT_LENGTH") != nullptr)
        {
            int contentLength = std::stoi((*headerList->get("CONTENT_LENGTH")));
            //body = (char *)malloc(contentLength + 1);
            //fread(body, contentLength, 1, stdin);
            char query[1024];
            std::string data;

            std::cin.read(query, contentLength);
            data = query;
            LOG(TRACE) << "Body: " << data << " length: " << std::to_string(contentLength);
        }
        else
        {
            LOG(TRACE) << "Body is empty";
        }
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
    char *body;
};

#endif