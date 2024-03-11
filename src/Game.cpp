#include "Game.h"

Game::Game(const std::string& logFilePath) : logger(logFilePath, true), window(logger) {}
Game::~Game() { cleanup(); }

void Game::init()
{
    logger.log(LogLevel::INFO, "Init Game...");
    window.create();
}

void Game::cleanup()
{
    window.close();
}

void Game::update()
{

}

void Game::render()
{

}

void Game::run()
{
    init();
    while (window.isClosed()) {
        window.pollEvents();
        update();
        render();
    }
    cleanup();
}
