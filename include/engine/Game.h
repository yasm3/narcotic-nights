#ifndef _GAME_H
#define _GAME_H

#include "Window.h"
#include "Graphics.h"
#include "AssetManager.h"
#include "Input.h"
#include "Tileset.h"
#include "Tilemap.h"
#include "DevMenu.h"

class Game {
    public:
        Game();
        ~Game();
        void init();
        void cleanup();
        void update();
        void draw();
        void run();
    private:
        bool m_running;
        float m_last_frame_time;

        Window m_window;
        SDL_Renderer* m_renderer;
        Graphics m_graphics;
        AssetManager m_assetManager;
        Input m_input;

        DevMenu m_devMenu;

        friend class DevMenu;

};

#endif
