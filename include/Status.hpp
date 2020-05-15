#ifndef __HTTP_STATUS_H__
#define __HTTP_STATUS_H__

#include <string>

namespace http
{
struct Status
{
    const int code;
    const std::string reasonPhrase;

    Status(const int _code, const std::string _reasonPhrase) : code(_code), reasonPhrase(_reasonPhrase)
    {
    }
};
} // namespace http
#endif