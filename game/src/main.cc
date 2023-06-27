
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

/*#include <iostream>
#include "../../thread/include/system.h"
#include "../include/main_class_T5.h"
#include "../../thread/include/thread.h"

__USING_API

Thread *Main::ping_pong_threads[5];
Semaphore *Main::sem;

int main(void)
{
    System::init(&Main::run);
}*/