#include "Window.h"
#include <iostream>
#include <SDL2/SDL_image.h>

Window::Window(const std::string& t, int w, int h): m_title(t), m_width(w), m_height(h), m_running(true), m_window(nullptr), m_renderer(nullptr) {}
Window::~Window() { cleanup(); }

void Window::init()
{
    // SDL initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw std::runtime_error("Failed to init SDL: " + std::string(SDL_GetError()));
    }

    // SDL_Image initialization
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        throw std::runtime_error("Failed to init SDL_Image: " + std::string(SDL_GetError()));
    }

    // window creation
    m_window = SDL_CreateWindow(m_title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_width,
        m_height,
        SDL_WINDOW_SHOWN
    );
    if (m_window == nullptr) {
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL window: " + std::string(SDL_GetError()));
    }


    // renderer creation
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL renderer: " + std::string(SDL_GetError()));
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
}

void Window::cleanup()
{
    if (m_renderer != nullptr) {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }
    if (m_window != nullptr) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    IMG_Quit();
    SDL_Quit();
}

bool Window::isRunning() const { return m_running; }
SDL_Renderer* Window::getRenderer() const { return m_renderer; }

void Window::setTitle(const std::string& t)
{
    m_title = t;
    SDL_SetWindowTitle(m_window, t.c_str());
}

int Window::getWidth() const { return m_width; }
int Window::getHeight() const { return m_height; }

void Window::setWidth(int w)
{
    m_width = w;
    SDL_SetWindowSize(m_window, w, m_height);
}

void Window::setHeight(int h)
{
    m_height = h;
    SDL_SetWindowSize(m_window, m_width, h);
}

void Window::toggleFullscreen()
{
    Uint32 flag = SDL_WINDOW_FULLSCREEN;
    bool isFullScreen = SDL_GetWindowFlags(m_window) & flag;
    SDL_SetWindowFullscreen(m_window, isFullScreen ? 0 : flag);
    if (isFullScreen) {
        SDL_SetWindowSize(m_window, m_width, m_height);
        SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
}

void Window::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) m_running = false;
    }
}
