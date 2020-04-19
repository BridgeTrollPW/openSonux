#include <memory>

#include "src/OpenSonux.hpp"
#include "src/MiddlewareStack.hpp"
#include "impl/ExampleMiddleware.hpp"
#include "lib/easyloggingcpp/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[], char *envp[])
{

    el::Configurations conf("/var/www/opensonux.intern/app.conf");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);

    OpenSonux openSonux(envp);
    std::unique_ptr<ExampleMiddleware> a = std::make_unique<ExampleMiddleware>();
    MiddlewareStack::getInstance().push(a.get());
    MiddlewareStack::getInstance().push(a.get());

    openSonux.run();
}