#include <iostream>

#include "../../thread/include/system.h"
#include "../include/game.h"

__USING_API

int main(void)
{
    System::init(&Game::init);
    return 0;
}
