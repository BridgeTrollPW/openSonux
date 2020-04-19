#include "OpenSonux.hpp"
#include "HeaderList.hpp"
#include "../lib/easyloggingcpp/easylogging++.h"

OpenSonux::OpenSonux(char **envp)
{
    LOG(DEBUG) << "Starting OpenSonux";
    headerList = new HeaderList(envp);
}
OpenSonux::~OpenSonux()
{
    delete headerList;
}

void OpenSonux::run()
{
    MiddlewareStack::getInstance().execute();
    std::cout << "Status: 201 CREATED\r\n";
    std::cout << "content-type: application/json\r\n\n";
    std::cout << "{}";
    std::cout << "Connection header: " << *headerList->get("Connection");
    if(headerList->get("Connection") == NULL){
        std::cout << "Connection header is empty/null";
    }
}