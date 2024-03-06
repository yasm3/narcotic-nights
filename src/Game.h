#ifndef _GAME_H
#define _GAME_H

#include "Logger.h"
#include "Graphics.h"

class Game {
    public:
        Game(const std::string &logFilePath);
        ~Game();
        Logger lg;
        void init();
        void cleanup();
        
        void update();
        void render();
        void run();
    private:
        Graphics graphics;
};

#endif
