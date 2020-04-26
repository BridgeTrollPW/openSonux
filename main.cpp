#include "easylogging++.h"
#include "Application.hpp"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[], char *envp[])
{
    el::Configurations conf("app.conf");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);
    Application app(envp);
    return 0;
}