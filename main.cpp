#include <memory>

#include "src/OpenSonux.hpp"
#include "lib/easyloggingcpp/easylogging++.h"
#include "ExampleMiddleware.hpp"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[], char *envp[])
{
    el::Configurations conf("app.conf");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);

    OpenSonux openSonux(envp);
    openSonux.getMiddlewareStack()->push(new ExampleMiddleware());
    openSonux.run();
}