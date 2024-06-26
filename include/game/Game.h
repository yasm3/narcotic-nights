#ifndef _GAME_H
#define _GAME_H

#include "Window.h"
#include "Graphics.h"
#include "AssetManager.h"
#include "Input.h"
#include "Tileset.h"
#include "Tilemap.h"
#include "DevMenu.h"
#include "Room.h"
#include "Player.h"
#include "Dungeon.h"

enum GameState {
    PLAYING,
    MAINMENU
};

/**
 * @class Game
 * 
 * @brief Classe métier gérant tout le jeu
 */
class Game {
    public:
        Game();
        ~Game();
        void init();
        void cleanup();
        void update(float deltaTime);
        void draw();
        void run();
    private:
        bool m_running;
        float m_last_frame_time;
        GameState m_gamestate;

        Window m_window;
        SDL_Renderer* m_renderer;
        Graphics m_graphics;
        AssetManager m_assetManager;
        Input m_input;
        DevMenu m_devMenu;
        friend class DevMenu;

        // game parts
        Player m_player;
        Dungeon m_dungeon;
};

#endif
