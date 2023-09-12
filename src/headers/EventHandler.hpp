#ifndef EVENTHANDLER_CLASS
#define EVENTHANDLER_CLASS

#include <unordered_map>
#include <SDL2/SDL.h>

#include <iostream>

using pfunc = void (*)();
class EventHandler
{
private:
    std::unordered_map<Uint16, pfunc> registeredEvents;
    std::unordered_map<SDL_Keycode, pfunc> registeredKeys;

public:
    void SetEvent(Uint16 event, pfunc method)
    {
        registeredEvents[event] = method;
    }

    void SetKeyDownEvent(SDL_Keycode key, void (*method)())
    {
        registeredKeys[key] = method;
    }

    void Update()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_WINDOWEVENT:
                if (registeredEvents.find(event.window.event) != registeredEvents.end())
                    registeredEvents[event.window.event]();
                break;
            case SDL_KEYDOWN:
                if (registeredKeys.find(SDL_GetKeyFromScancode(event.key.keysym.scancode)) != registeredKeys.end())
                    registeredKeys[SDL_GetKeyFromScancode(event.key.keysym.scancode)]();
                break;
            default:
                if (registeredEvents.find(event.type) != registeredEvents.end())
                {
                    registeredEvents[event.type]();
                    break;
                }

                continue;
            };
            if (event.type == SDL_WINDOWEVENT && registeredEvents.find(event.window.event) != registeredEvents.end())
            {
                continue;
            }
        }
    }
};

#endif