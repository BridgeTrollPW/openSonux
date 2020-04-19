#ifndef __HTTP_STATUS_H__
#define __HTTP_STATUS_H__

#include <string>

namespace http
{
class Status
{
public:
    const int code;
    const std::string reasonPhrase;

    Status(const int _code, const std::string _reasonPhrase) : code(_code), reasonPhrase(_reasonPhrase)
    {
    }
};

const Status NOT_FOUND(404, "Not Found");
} // namespace http
#endif