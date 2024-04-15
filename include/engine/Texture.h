#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

/**
 * @class Texture
 * 
 * @brief Classe permettant de representer toutes les textures du jeu (abstrait la SDL dans ce cas)
 */
class Texture {
    public:
        Texture(SDL_Renderer* renderer, const std::string& filePath);
        Texture(SDL_Renderer* renderer, int width, int height);
        ~Texture();
        SDL_Texture* getNativeTexture() const;
        int getWidth() const;
        int getHeight() const;
        SDL_Texture* m_texture;
    private:
        int m_width, m_height;
};

#endif
