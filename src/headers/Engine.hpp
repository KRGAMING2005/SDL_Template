#ifndef ENGINE
#define ENGINE

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "EventHandler.hpp"

class Engine
{
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    EventHandler *eventHandler = nullptr;

    SDL_Color color = {11, 11, 11, 255};

    bool running = true;

    static Engine *instance;

public:
    EventHandler *getEventhandler()
    {
        return eventHandler;
    }

    Engine()
    {
        if (SDL_INIT_VIDEO < 0)
        {
            printf("Video initialization for SDL failed: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        if (TTF_Init() < 0)
        {
            printf("TTF initialization for SDL failed: %s\n", TTF_GetError());
            exit(EXIT_FAILURE);
        }

        window = SDL_CreateWindow("No name yet", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        eventHandler = new EventHandler();

        eventHandler->SetEvent(SDL_QUIT, []()
                               { Engine::getInstance()->Stop(); });
    }

    ~Engine()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        TTF_Quit();
        SDL_Quit();
    }

    static Engine *getInstance()
    {
        return (instance != nullptr) ? instance : instance = new Engine();
    }

    void Stop()
    {
        this->running = false;
    }

    int Start()
    {
        while (this->running)
        {
            this->eventHandler->Update();
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderClear(renderer);

            // TODO: Updatables refer to LoveL05 enigne because this is rewrite.

            SDL_RenderPresent(renderer);
        }
        return 0;
    }
};

#endif