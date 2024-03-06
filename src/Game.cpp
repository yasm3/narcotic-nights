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
