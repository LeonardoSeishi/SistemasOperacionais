#include "../include/traits.h"
#include "../include/window.h"

__USING_API
int main(void)
{
    GameWindow* window = new GameWindow();

    window->run();

    return 0;
}
