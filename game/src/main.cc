#include <iostream>
#include "../../thread/include/traits.h"
#include "../../thread/include/system.h"

#include "../include/window.h"

__USING_API

int main(void)
{
    // GameWindow* window = new GameWindow();
    // Game * game = new Game();
    System::init(&Game::init);
    // game->startGame();
    // window->run();
    // std::cout << teste(a) << "\n";
    return 0;
}
