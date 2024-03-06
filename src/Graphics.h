#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL2/SDL.h>

class Game;

class Graphics {
    public:
        Graphics(Game& game);
        ~Graphics();
        void init();
        void cleanup();
    private:
        Game& game;
        SDL_Window* window = nullptr;
};

#endif
