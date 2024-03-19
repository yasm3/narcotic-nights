#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Texture {
    public:
        Texture(SDL_Renderer* renderer, const std::string& imgPath);
        ~Texture();
        SDL_Texture* getTexture() const;
    private:
        SDL_Texture* m_texture;
};

#endif
