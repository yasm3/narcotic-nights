#include "Game.h"

int main(int argc, char* argv[])
{
    Game g("log.txt");
    g.init();
    g.cleanup();
    return 0;
}
