#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <string>

#include "../HeaderList.hpp"
#include "Status.hpp"

//https://tools.ietf.org/html/rfc3875#section-6
class Response
{
public:
    Response()
    {
        this->headerList = new HeaderList();
        this->statusCode = new http::Status(200, "OK");
    }

    ~Response()
    {
        delete headerList;
        delete statusCode;
    }

    std::string *getHeader(const std::string &key)
    {
        return headerList->get(key);
    }

    void addHeader(const std::string &key, const std::string &value)
    {
        headerList->add(key, value);
    }

    Response *status(http::Status *code)
    {
        delete this->statusCode;
        this->statusCode = code;
        return this;
    }

    Response *entity(const std::string &body)
    {
        this->body = body;
        return this;
    }

    std::string build()
    {
        std::string response;
        return response
            .append("Status: ")
            .append(std::to_string(statusCode->code))
            .append(" ")
            .append(statusCode->reasonPhrase)
            .append("\r\n")
            .append(headerList->build())
            .append("\n")
            .append(body);
    }

private:
    HeaderList *headerList;
    std::string body;
    http::Status *statusCode;
};

#endif