#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <memory>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Texture.h"
#include "Tilemap.h"
#include "Vector2D.h"

/**
 * @class Graphics
 * 
 * @brief Classe responsable de tous les rendus à l'écran et permet d'abstraire la bibliothèque graphique utilisée (basé sur SDL2)
 */
class Graphics {
    public:
        Graphics();
        ~Graphics();
        void attachWindow(Window* window);

        void clear();
        void clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a); ///< Efface écran
        void present(); ///< Swap double buffer
        int getScale() const;
        void setScale(int newScale); ///< Change la mise à l'échelle de l'affichage
        const Window* getWindow() const;
        Vector2D<int> getMousePos() const;

        // Drawing methods
        void draw(const Texture& texture, int x, int y); ///< Dessiner une texture avec position
        void draw(const Texture& texture, int x, int y, int w, int h);
        void draw(const Texture& texture, int x, int y, int scale);
        void drawTilemap(const Tilemap& tilemap); ///< Dessiner une Tilemap
        void drawRectangle(Vector2D<int> position, Vector2D<int> dimensions, int r, int g, int b);

    private:
        Window* m_window;
        SDL_Renderer* m_renderer;
        int m_scale;
};

#endif
