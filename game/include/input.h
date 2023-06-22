#ifndef input_h
#define input_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "traits.h"
#include "spaceship.h"
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
        game_running_status = true;
        // Inicializa thread
        // Inicializa mutex
        input_mutex = new Semaphore(1);
    }
    ~Input()
    {
        // Delete thread
        delete input_mutex;
        std::cout << "Thread input finalizada\n";
    }
    void prun();
    void pkill();
    void checkInput();

private:
    bool game_running_status;
    PlayerShip *player;
    Semaphore *input_mutex;
};

__END_API

#endif