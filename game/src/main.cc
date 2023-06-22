#include "../../thread/include/traits.h"
#include "../../thread/include/system.h"

#include "../include/window.h"

__USING_API
int main(void)
{
    // GameWindow* window = new GameWindow();
    Game * game = new Game();
    game->startGame();    
    // window->run();

    return 0;
}
