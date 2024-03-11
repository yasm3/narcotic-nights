#ifndef _GAME_H
#define _GAME_H

#include "Logger.h"
#include "Window.h"

class Game {
    public:
        Game(const std::string &logFilePath);
        ~Game();

        Logger logger;

        void init();
        void cleanup();
        void update();
        void render();
        void run();
    private:
        Window window;
};

#endif
