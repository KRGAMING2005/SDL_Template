#include <iostream>
#include <SDL2/SDL.h>

#include "headers/Engine.hpp"

using namespace std;

Engine *Engine::instance = nullptr;

int main(int argc, char *argv[])
{
    Engine *engine = Engine::getInstance();
    return engine->Start();
}