#include "Graphics.h"

Graphics::Graphics() : m_window(nullptr), m_renderer(nullptr), m_scale(1) {}

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

int Graphics::getScale() const
{
    return m_scale;
}

void Graphics::setScale(int newScale)
{
    m_scale = newScale;
}

const Window* Graphics::getWindow() const
{
    return m_window;
}

Vector2D<int> Graphics::getMousePos() const
{
    Vector2D<int> pos(0);
    SDL_GetMouseState(&pos.x, &pos.y);
    return pos;
}

void Graphics::draw(const Texture& t, int x, int y)
{
    SDL_Rect dstRect = { x,y,0,0 };
    SDL_QueryTexture(t.getNativeTexture(), nullptr, nullptr, &dstRect.w, &dstRect.h);
    SDL_RenderCopy(m_renderer, t.getNativeTexture(), nullptr, &dstRect);
}

void Graphics::draw(const Texture& t, int x, int y, int w, int h)
{
    SDL_Rect dstRect = { x,y,w,h };
    SDL_RenderCopy(m_renderer, t.getNativeTexture(), nullptr, &dstRect);
}

void Graphics::draw(const Texture& t, int x, int y, int scale)
{
    SDL_Rect dstRect = { x,y,0,0 };
    SDL_QueryTexture(t.getNativeTexture(), nullptr, nullptr, &dstRect.w, &dstRect.h);
    dstRect.w *= scale;
    dstRect.h *= scale;
    SDL_RenderCopy(m_renderer, t.getNativeTexture(), nullptr, &dstRect);
}

void Graphics::drawTilemap(const Tilemap& tm)
{
    int tileWidth = tm.getTileset().getTileWidth();
    int tileHeight = tm.getTileset().getTileHeight();

    int tilesNumberWidth = tm.getWidth();
    int tilesNumberHeight = tm.getHeight();

    int windowWidth = m_window->getWidth();
    int windowHeight = m_window->getHeight();

    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;

    int startScreenX = centerX - (tilesNumberWidth * tileWidth * m_scale) / 2;
    int startScreenY = centerY - (tilesNumberHeight * tileHeight * m_scale) / 2;

    int tileX, tileY;
   
    for (int col = 0; col < tilesNumberHeight; col++) {
        for (int row = 0; row < tilesNumberWidth; row++) {
            tileX = row * tileWidth * m_scale;
            tileY = col * tileHeight * m_scale;
            draw(tm.getTile(row, col), tileX, tileY, m_scale);
        }
    }
}

void Graphics::drawRectangle(Vector2D<int> position, Vector2D<int> dimensions, int r, int g, int b)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    dimensions = dimensions * m_scale;
    SDL_Rect rect = { position.x, position.y, dimensions.x, dimensions.y };
    SDL_RenderDrawRect(m_renderer, &rect);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
}
