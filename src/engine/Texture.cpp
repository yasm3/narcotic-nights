#include "Texture.h"
#include <SDL2/SDL_image.h>

Texture::Texture(SDL_Renderer* r, const std::string& ip) : m_texture(nullptr), m_width(0), m_height(0)
{
    // load image as SDL texture
    m_texture = IMG_LoadTexture(r, ip.c_str());
    if (m_texture == nullptr) {
        throw std::runtime_error("Failed to load image: " + std::string(IMG_GetError()));
    }
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_width, &m_height);
}

Texture::Texture(SDL_Renderer* r, int w, int h) : m_texture(nullptr), m_width(0), m_height(0)
{
    m_texture = SDL_CreateTexture(r, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC | SDL_TEXTUREACCESS_TARGET, w, h);
    m_width = w;
    m_height = h;
}

Texture::~Texture()
{
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
    }
}

SDL_Texture* Texture::getTexture() const
{
    return m_texture;
}

int Texture::getWidth() { return m_width; }
int Texture::getHeight() { return m_height; }
