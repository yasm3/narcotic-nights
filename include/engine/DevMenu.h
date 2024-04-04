#ifndef _DEVMENU_H
#define _DEVMENU_H

#include "imgui.h"

class Game;

class DevMenu {
    public:
        DevMenu(Game& game);
        void toggleMenu();
        bool isOpen();

        void render();
    private:
        Game& m_game;
        bool m_showMainMenu;
};

#endif