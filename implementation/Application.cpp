#include "Application.hpp"

Application::Application() {
  EmbeddedServer embeddedServer;
  embeddedServer.start();
}