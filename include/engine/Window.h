#ifndef _WINDOW_H
#define _WINDOW_H

#include <string>
#include <SDL2/SDL.h>

class Window {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        void init();
        void cleanup();
        bool isRunning() const;
        SDL_Renderer* getRenderer() const;
        void setTitle(const std::string& title);
        void setWidth(int width);
        int getWidth() const;
        int getHeight() const;
        void setHeight(int height);
        void toggleFullscreen();
        void handleEvents();
    private:
        bool m_running;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        std::string m_title;
        int m_width;
        int m_height;
};

#endif
