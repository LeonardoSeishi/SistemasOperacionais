#ifndef input_h
#define input_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "game.h"


__BEGIN_API

class Input
{
public:
    // Thread* thread;
    Input(PlayerShip* player_ptr)
    {
        player = player_ptr;
        // game_window = Game::getWindow();
        // Inicializa thread
        // Inicializa mutex
        // input_mutex = new Semaphore(1);
    }
    ~Input()
    {
        // Delete thread
        // delete input_mutex;
        std::cout << "Thread input finalizada\n";
    }
    static void run();
    void kill();
    void checkInput();

private:
    static PlayerShip *player;
    // static GameWindow &game_window;
    Semaphore *input_mutex;

};

__END_API

#endif