#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <memory>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Texture.h"
#include "Tilemap.h"

class Graphics {
    public:
        Graphics();
        ~Graphics();
        void attachWindow(Window* window);

        void clear();
        void clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        void present();
        int getScale() const;
        void setScale(int newScale);
        const Window* getWindow() const;

        // Drawing methods
        void draw(const Texture& texture, int x, int y);
        void draw(const Texture& texture, int x, int y, int w, int h);
        void draw(const Texture& texture, int x, int y, int scale);
        void drawTilemap(const Tilemap& tilemap);
    private:
        Window* m_window;
        SDL_Renderer* m_renderer;
        int m_scale;
};

#endif
