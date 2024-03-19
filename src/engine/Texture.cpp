#include "Texture.h"
#include <SDL2/SDL_image.h>

Texture::Texture(SDL_Renderer* r, const std::string& ip) : m_texture(nullptr)
{
    // load image as SDL texture
    m_texture = IMG_LoadTexture(r, ip.c_str());
    if (m_texture == nullptr) {
        throw std::runtime_error("Failed to load image: " + std::string(IMG_GetError()));
    }
}

Texture::~Texture()
{
    SDL_DestroyTexture(m_texture);
}

SDL_Texture* Texture::getTexture() const
{
    return m_texture;
}
