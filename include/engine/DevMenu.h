#ifndef _DEVMENU_H
#define _DEVMENU_H

#include "imgui.h"

class Game;

/**
 * @class DevMenu
 * 
 * @brief Classe permettant d'afficher un menu de développement (touche T), utile pour le debug
 */
class DevMenu {
    public:
        DevMenu(Game& game);
        void toggleMenu(); ///< Afficher/cache menu
        bool isOpen(); ///< Etat

        void render(); ///< Rendre le menu
    private:
        Game& m_game;
        bool m_showMainMenu;
};

#endif
