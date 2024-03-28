#ifndef _GAME_H
#define _GAME_H

#include "Window.h"
#include "Graphics.h"
#include "Input.h"
#include "GameObject.h"
#include "Tileset.h"

class Game {
    public:
        Game();
        ~Game();
        void init();
        void cleanup();
        void update(Uint32 deltaTime);
        void draw();
        void run();
    private:
        Window m_window;
        SDL_Renderer* m_renderer;
        Graphics m_graphics;
        Input m_input;

        // temporaire
        GameObject playerObject;
};

#endif