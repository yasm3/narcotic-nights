#ifndef _WINDOW_H
#define _WINDOW_H

#include <SDL2/SDL.h>
#include "Logger.h"

class Window {
    public:
        Window(Logger& logger);
        void create();
        void close();
        void pollEvents();
        bool isClosed();
    private:
        Logger& logger;
        bool running;
        SDL_Window* window;
};

#endif
