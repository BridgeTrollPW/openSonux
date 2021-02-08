#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <memory>
#include <string>

#include "HeaderList.hpp"
#include "Status.hpp"

//https://tools.ietf.org/html/rfc3875#section-6
class Response
{
public:
    Response()
    {
        this->headerList = std::make_unique<HeaderList>();
        this->statusCode = std::make_unique<http::Status>(200, "OK");
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
        //avoid memory leak when replacing status code with new pointer -> 
        //current statusCode will not be deleted and leaked since I have no pointer left to that memory address
        this->statusCode.reset(code);
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
    std::unique_ptr<HeaderList> headerList;
    std::string body;
    std::unique_ptr<http::Status> statusCode;
};

#endif