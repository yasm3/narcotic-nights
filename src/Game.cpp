#include "Game.h"

Game::Game(const std::string& logFilePath) : lg(logFilePath, true), graphics(*this) {}
Game::~Game() { cleanup(); }

void Game::init()
{
    lg.log(LogLevel::INFO, "Init Game");
    graphics.init();
}

void Game::cleanup()
{
    graphics.cleanup();
}

void Game::update()
{
}

void Game::render()
{
    graphics.render();
}

void Game::run()
{
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        render();
    }
}
