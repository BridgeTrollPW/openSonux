#include "easylogging++.h"
#include "Application.hpp"

INITIALIZE_EASYLOGGINGPP

auto main(int argc, char *argv[], char *envp[]) -> int
{
    el::Configurations conf("app.conf");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);
    Application app(envp);
    return 0;
}