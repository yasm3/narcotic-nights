#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Texture {
    public:
        Texture(SDL_Renderer* renderer, const std::string& imgPath);
        Texture(SDL_Renderer* renderer, int width, int height);
        ~Texture();
        SDL_Texture* getTexture() const;
        int getWidth();
        int getHeight();
    private:
        SDL_Texture* m_texture;
        int m_width, m_height;
};

#endif
