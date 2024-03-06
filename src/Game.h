#ifndef _GAME_H
#define _GAME_H

#include "Logger.h"

class Game {
	public:
		Game(const std::string &logFilePath);
		void init();
		void cleanup();
		
		void update();
		void render();
		void run();
	private:
		Logger logger;
};

#endif