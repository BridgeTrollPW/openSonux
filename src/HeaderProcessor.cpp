#include "HeaderProcessor.hpp"

#include <iostream>

HeaderProcessor::HeaderProcessor(char **envp)
{
    std::string envLine;
    for (char **env = envp; *env != 0; env++)
    {
        envLine = std::string(*env);
        if (envLine.starts_with("HTTP"))
        {
            headers.emplace(envLine.substr(0, envLine.find_first_of("=")), envLine.substr(envLine.find_first_of("=") + 1));
        }
        else
        {
            envs.emplace(envLine.substr(0, envLine.find_first_of("=")), envLine.substr(envLine.find_first_of("=") + 1));
        }
    }
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

const std::string HTTPHeader::HOST = "HTTP_HOST";
const std::string HTTPHeader::USER_AGENT = "HTTP_USER_AGENT";
const std::string HTTPHeader::ACCEPT = "HTTP_ACCEPT";
const std::string HTTPHeader::CONTENT_TYPE = "HTTP_CONTENT_TYPE";