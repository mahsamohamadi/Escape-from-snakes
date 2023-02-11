#include "game.h"

int main()
{
    //game object
    game game;
    //game loop
    while(game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}

