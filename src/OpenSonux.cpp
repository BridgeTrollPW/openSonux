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
    std::cout << "content-type: application/json\n\n";
    std::cout << "{}";
    std::cout << "Token header: " << headerList->get("token");
    if(headerList->get("token") == NULL){
        std::cout << "Token header is null";
    }
}