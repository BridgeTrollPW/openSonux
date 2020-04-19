#include "src/OpenSonux.hpp"

int main(int argc, char *argv[], char *envp[]){
    OpenSonux openSonux(envp);
    openSonux.run();
}