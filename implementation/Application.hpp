#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <memory>

#include "EmbeddedServer.hpp"

class Application {
public:
  Application(char **envp) {
    EmbeddedServer embeddedServer;
    embeddedServer.start();
  }
};

#endif