#ifndef _INPUT_H
#define _INPUT_H

#include <SDL2/SDL.h>

/**
 * @class Input
 * 
 * @brief Classe gérant les entrées clavier (basé sur SDL)
 */
class Input {
    public:
        Input();
        ~Input();

        void update();
        bool isKeyDown(SDL_Scancode key); ///< Permet de savoir si une touche est enfoncée ou non
    private:
        const Uint8* m_keystate;
};

#endif
