#include "Game.h"

Game::Game(const std::string& logFilePath) : logger(logFilePath, true) {}

void Game::init()
{
	logger.log(LogLevel::INFO, "Init Game");
}
