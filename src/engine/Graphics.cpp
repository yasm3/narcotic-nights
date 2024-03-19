#include "Graphics.h"

Graphics::Graphics(SDL_Renderer* r) : m_renderer(r) {}

Graphics::~Graphics() {}

void Graphics::setRenderer(SDL_Renderer* r)
{
    m_renderer = r;
}

void Graphics::clear()
{
    SDL_RenderClear(m_renderer);
}

void Graphics::clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
    SDL_RenderClear(m_renderer);
}

void Graphics::present()
{
    SDL_RenderPresent(m_renderer);
}

void Graphics::draw(Texture* t, int x, int y)
{
    SDL_Rect dstRect = { x,y,0,0 };
    SDL_QueryTexture(t->getTexture(), nullptr, nullptr, &dstRect.w, &dstRect.h);
    SDL_RenderCopy(m_renderer, t->getTexture(), nullptr, &dstRect);
}

void Graphics::draw(Texture* t, int x, int y, int w, int h)
{
    SDL_Rect dstRect = { x,y,w,h };
    SDL_RenderCopy(m_renderer, t->getTexture(), nullptr, &dstRect);
}
