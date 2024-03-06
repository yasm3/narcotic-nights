#include "Graphics.h"
#include "Game.h"

Graphics::Graphics(Game& game) : game(game) {}
Graphics::~Graphics() { cleanup(); }

void Graphics::init()
{
    game.lg.log(LogLevel::INFO, "Init Graphics");
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        game.lg.log(LogLevel::ERROR, "SDL could not initialize!");
        game.lg.log(LogLevel::ERROR, SDL_GetError());
        std::terminate;
    }
    else {
        window = SDL_CreateWindow("Narcotic Nights",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            500,
            500,
            SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            game.lg.log(LogLevel::ERROR, "Window could not be created!");
            game.lg.log(LogLevel::ERROR, SDL_GetError());
            std::terminate;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            game.lg.log(LogLevel::ERROR, "Renderer could not be created!");
            game.lg.log(LogLevel::ERROR, SDL_GetError());
            std::terminate;
        }
    }
}

void Graphics::cleanup()
{
    game.lg.log(LogLevel::INFO, "Cleanup Graphics");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
