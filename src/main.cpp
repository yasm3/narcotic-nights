#include "Game.h"

int main(int argc, char* argv[])
{
    Game g("log.txt");
    g.init();
    g.run();
    g.cleanup();
    return 0;
}
