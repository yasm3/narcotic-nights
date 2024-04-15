#include "Game.h"
#include <random>

int main(int charc, char* argv[])
{
    srand(time(nullptr));
    Game game;
    game.run();
    return 0;
}
