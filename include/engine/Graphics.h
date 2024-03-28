#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL2/SDL.h>
#include <unordered_map>
#include <memory>
#include "Texture.h"

class Graphics {
    public:
        Graphics(SDL_Renderer* renderer);
        ~Graphics();
        void setRenderer(SDL_Renderer* renderer);

        void clear();
        void clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        void present();

        // Drawing methods
        void draw(std::shared_ptr<Texture> texture, int x, int y);
        void draw(std::shared_ptr<Texture> texture, int x, int y, int w, int h);
        void draw(std::shared_ptr<Texture> texture, int x, int y, int scale);

        // Texture methods
        std::shared_ptr<Texture> createTextureFromImage(const std::string& imgPath);
    private:
        SDL_Renderer* m_renderer;
};

#endif
