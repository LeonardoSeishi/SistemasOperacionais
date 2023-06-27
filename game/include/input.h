#ifndef input_h
#define input_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "window.h"
#include "../../thread/include/traits.h"
#include "../../thread/include/thread.h"
#include "../../thread/include/semaphore.h"

__BEGIN_API

class Input
{
public:
    // Thread* thread;
    Input(PlayerShip* player_ptr)
    {
        player = player_ptr;
    }
    ~Input()
    {
        std::cout << "Thread input finalizada\n";
    }
    static void run();
    void kill();
    void checkInput();

private:
    static PlayerShip *player;
    Semaphore *input_mutex;

};

__END_API

#endif