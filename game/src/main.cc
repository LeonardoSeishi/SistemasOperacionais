
#include <iostream>
#include "../../thread/include/traits.h"
#include "../../thread/include/system.h"

#include "../include/window.h"

__USING_API

int main(void)
{
    System::init(&Game::init);
    return 0;
}