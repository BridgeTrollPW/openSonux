#ifndef __HEADER_PROCESSOR__H__
#define __HEADER_PROCESSOR__H__

#include <string>
#include <map>

class HeaderProcessor final
{
public:
    HeaderProcessor(char **envp);

private:
    std::map<const std::string, const std::string> headers;
    std::map<const std::string, const std::string> envs;
};

class CGIEnvironment final
{
public:
    const static std::string CONTEXT_PREFIX;
    const static std::string CONTEXT_DOCUMENT_ROOT;

    const static std::string DOCUMENT_ROOT;

    const static std::string GATEWAY_INTERFACE;

    const static std::string SERVER_SIGNATURE;
    const static std::string SERVER_SOFTWARE;
    const static std::string SERVER_NAME;
    const static std::string SERVER_ADDR;
    const static std::string SERVER_PORT;
    const static std::string SERVER_ADMIN;
    const static std::string SERVER_PROTOCOL;

    const static std::string REMOTE_ADDR;
    const static std::string REMOTE_PORT;

    const static std::string REQUEST_SCHEME;
    const static std::string REQUEST_URI;
    const static std::string REQUEST_METHOD;

    const static std::string SCRIPT_FILENAME;
    const static std::string SCRIPT_NAME;

    const static std::string QUERY_STRING;

    const static std::string PATH;
    const static std::string PATH_INFO;
    const static std::string PATH_TRANSLATED;
};

class HTTPHeader final
{
public:
    const static std::string HOST;
    const static std::string USER_AGENT;
    const static std::string ACCEPT;
    const static std::string CONTENT_TYPE;
};
#endif