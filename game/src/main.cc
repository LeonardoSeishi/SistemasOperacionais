#include <iostream>
#include "../../thread/include/traits.h"
#include "../../thread/include/system.h"

#include "../include/window.h"

__USING_API
int a = 1;
int teste(int& i) {
    return i++;
}
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
