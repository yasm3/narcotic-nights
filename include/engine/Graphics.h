#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL2/SDL.h>
#include "Texture.h"

class Graphics {
    public:
        Graphics(SDL_Renderer* renderer);
        ~Graphics();
        void setRenderer(SDL_Renderer* renderer);

        void clear();
        void clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        void present();

        void draw(Texture* texture, int x, int y);
        void draw(Texture* texture, int x, int y, int w, int h);
    private:
        SDL_Renderer* m_renderer;
};

#endif
