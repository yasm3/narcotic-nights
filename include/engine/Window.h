#ifndef _WINDOW_H
#define _WINDOW_H

#include <string>
#include <SDL2/SDL.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

/**
 * @class Window
 * 
 * @brief Classe representant la fenêtre du jeu (abstrait la SDL)
 * 
 */
class Window {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        void init();
        void initImGui();
        void cleanup();
        bool isRunning() const;
        SDL_Renderer* getRenderer() const;
        void setTitle(const std::string& title);
        void setWidth(int width);
        int getWidth() const;
        int getHeight() const;
        void setHeight(int height);
        void toggleFullscreen();
    private:
        bool m_running;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        std::string m_title;
        int m_width, m_height = 0;
};

#endif
