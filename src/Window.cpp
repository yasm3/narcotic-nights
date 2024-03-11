#include "Window.h"
#include <exception>

Window::Window(Logger& logger) : logger(logger), window(nullptr), running(true)  {}

void Window::create() {
    logger.log(LogLevel::INFO, "SDL Initialization");
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        logger.log(LogLevel::ERROR, "SDL could not initialize");
        logger.log(LogLevel::ERROR, SDL_GetError());
        std::terminate;
    }
    else {
        logger.log(LogLevel::INFO, "Window creation");
        window = SDL_CreateWindow("Narcotic Nights",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            500,
            500,
            SDL_WINDOW_SHOWN
        );
        if (window == nullptr) {
            logger.log(LogLevel::ERROR, "Window could not be created");
            logger.log(LogLevel::ERROR, SDL_GetError());
            std::terminate;
        }
    }
}

void Window::close()
{
    if (window != nullptr) {
        logger.log(LogLevel::INFO, "Destroying window");
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

void Window::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) running = false;
    }
}

bool Window::isClosed()
{
    return running;
}
