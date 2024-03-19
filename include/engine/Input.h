#ifndef _INPUT_H
#define _INPUT_H

#include <SDL2/SDL.h>

class Input {
    public:
        Input();
        ~Input();

        void update();
        bool isKeyDown(SDL_Scancode key) const;
    private:
        const Uint8* m_keystate;
};

#endif
