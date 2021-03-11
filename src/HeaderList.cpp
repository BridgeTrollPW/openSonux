#include <algorithm>
#include <iostream>
#include <locale>

#include "../include/HeaderList.hpp"

HeaderList::HeaderList(){}

HeaderList::HeaderList(char **envp)
{
    std::string envLine;
    for (char **env = envp; *env != 0; env++)
    {
        envLine = std::string(*env);
        std::string key = envLine.substr(0, envLine.find_first_of("="));
        std::string value = envLine.substr(envLine.find_first_of("=") + 1);

        if (key.rfind("HTTP", 0) == 0)
        {
            log.trace("Adding http header %s : %s", key.c_str(), value.c_str());
            key = key.substr(5);
            size_t start_pos = key.find("_");
            if (start_pos != std::string::npos)
            {
                key.replace(start_pos, 1, "-");
            }
        }
        else
        {
            log.trace("Adding env header %s : %s", key.c_str(), value.c_str());
        }
        add(key, value);
    }
}

void HeaderList::add(std::string key, std::string value)
{
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);

    headers.insert(std::pair<std::string, std::string>(key, value));
}
/**
 * Get a header by key, case insensitive
 * returns nullptr if header was not found in the request
 * */
std::string *HeaderList::get(std::string key)
{
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
    try
    {
        return &headers.at(key);
    }
    catch (const std::out_of_range &oor)
    {
        return nullptr;
    }
}

std::string HeaderList::build()
{
    std::string headerlines;
    for(const auto& [key, value] : headers)
    {
        headerlines.append(key).append(": ").append(value).append("\r\n");
    }
    return headerlines;
}

const std::string CGIEnvironment::CONTEXT_PREFIX = "CONTEXT_PREFIX";
const std::string CGIEnvironment::CONTEXT_DOCUMENT_ROOT = "CONTEXT_DOCUMENT_ROOT";
const std::string CGIEnvironment::DOCUMENT_ROOT = "DOCUMENT_ROOT";
const std::string CGIEnvironment::GATEWAY_INTERFACE = "GATEWAY_INTERFACE";
const std::string CGIEnvironment::SERVER_SIGNATURE = "SERVER_SIGNATURE";
const std::string CGIEnvironment::SERVER_SOFTWARE = "SERVER_SOFTWARE";
const std::string CGIEnvironment::SERVER_NAME = "SERVER_NAME";
const std::string CGIEnvironment::SERVER_ADDR = "SERVER_ADDR";
const std::string CGIEnvironment::SERVER_PORT = "SERVER_PORT";
const std::string CGIEnvironment::SERVER_ADMIN = "SERVER_ADMIN";
const std::string CGIEnvironment::SERVER_PROTOCOL = "SERVER_PROTOCOL";
const std::string CGIEnvironment::REMOTE_ADDR = "REMOTE_ADDR";
const std::string CGIEnvironment::REMOTE_PORT = "REMOTE_PORT";
const std::string CGIEnvironment::REQUEST_SCHEME = "REQUEST_SCHEME";
const std::string CGIEnvironment::REQUEST_URI = "REQUEST_URI";
const std::string CGIEnvironment::REQUEST_METHOD = "REQUEST_METHOD";
const std::string CGIEnvironment::SCRIPT_FILENAME = "SCRIPT_FILENAME";
const std::string CGIEnvironment::SCRIPT_NAME = "SCRIPT_NAME";
const std::string CGIEnvironment::QUERY_STRING = "QUERY_STRING";
const std::string CGIEnvironment::PATH = "PATH";
const std::string CGIEnvironment::PATH_INFO = "PATH_INFO";
const std::string CGIEnvironment::PATH_TRANSLATED = "PATH_TRANSLATED";

const std::string HTTPHeader::HOST = "HOST";
const std::string HTTPHeader::USER_AGENT = "USER_AGENT";
const std::string HTTPHeader::ACCEPT = "ACCEPT";
const std::string HTTPHeader::CONTENT_TYPE = "CONTENT_TYPE";