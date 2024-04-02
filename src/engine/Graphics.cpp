#include "Graphics.h"

Graphics::Graphics(Window* window) : m_window(nullptr), m_renderer(nullptr) {}

Graphics::~Graphics() {}

void Graphics::attachWindow(Window* window)
{
    m_window = window;
    m_renderer = window->getRenderer();
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

void Graphics::draw(std::shared_ptr<Texture> t, int x, int y)
{
    SDL_Rect dstRect = { x,y,0,0 };
    SDL_QueryTexture(t->getNativeTexture(), nullptr, nullptr, &dstRect.w, &dstRect.h);
    SDL_RenderCopy(m_renderer, t->getNativeTexture(), nullptr, &dstRect);
}

void Graphics::draw(std::shared_ptr<Texture> t, int x, int y, int w, int h)
{
    SDL_Rect dstRect = { x,y,w,h };
    SDL_RenderCopy(m_renderer, t->getNativeTexture(), nullptr, &dstRect);
}

void Graphics::draw(std::shared_ptr<Texture> t, int x, int y, int scale)
{
    SDL_Rect dstRect = { x,y,0,0 };
    SDL_QueryTexture(t->getNativeTexture(), nullptr, nullptr, &dstRect.w, &dstRect.h);
    dstRect.w *= scale;
    dstRect.h *= scale;
    SDL_RenderCopy(m_renderer, t->getNativeTexture(), nullptr, &dstRect);
}

void Graphics::drawTilemap(const Tilemap& tm)
{
    int tileWidth = tm.getTileset()->getTileWidth();
    int tileHeight = tm.getTileset()->getTileHeight();

    int tilesNumberWidth = tm.getWidth();
    int tilesNumberHeight = tm.getHeight();

    int mapWidth = tilesNumberWidth * tileWidth;
    int mapHeight = tilesNumberHeight * tileHeight;

    int windowWidth = m_window->getWidth();
    int windowHeight = m_window->getHeight();

    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;

    int scale = std::min((float)windowWidth / mapWidth, (float)windowHeight / mapHeight);

    int startScreenX = centerX - (tilesNumberWidth * tileWidth * scale) / 2;
    int startScreenY = centerY - (tilesNumberHeight * tileHeight * scale) / 2;

    int tileX, tileY;

    for (int col = 0; col < tilesNumberHeight; col++) {
        for (int row = 0; row < tilesNumberWidth; row++) {
            tileX = row * tileWidth * scale + startScreenX;
            tileY = col * tileHeight * scale + startScreenY;
            draw(tm.getTile(row, col), tileX, tileY, scale);
        }
    }
}
