#include "Window.h"
#include <iostream>
#include <SDL2/SDL_image.h>

Window::Window(const std::string& t, int w, int h) : m_title(t), m_width(w), m_height(h), m_running(true), m_window(nullptr), m_renderer(nullptr) {}
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

    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    // window creation
    m_window = SDL_CreateWindow(m_title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_width,
        m_height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI
    );
    if (m_window == nullptr) {
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL window: " + std::string(SDL_GetError()));
    }

    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    // renderer creation
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == nullptr) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL renderer: " + std::string(SDL_GetError()));
    }

    initImGui();
}

void Window::initImGui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    ImGui::StyleColorsDark();
    
    ImGui_ImplSDL2_InitForSDLRenderer(m_window, m_renderer);
    ImGui_ImplSDLRenderer2_Init(m_renderer);
}

void Window::cleanup()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    
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
    Uint32 flags = SDL_GetWindowFlags(m_window);
    if (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
        SDL_SetWindowFullscreen(m_window, 0);
    }
    else {
        SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
}
