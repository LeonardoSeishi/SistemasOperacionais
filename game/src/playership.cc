#include "../include/spaceship.h"
//PLAYER

__BEGIN_API

void PlayerShip::runPlayerShip() {
    std::cout << "Chegou no run playership\n";

    while (Game::isWindowOpen()) {
        // std::cout << "Game::isWindowOpen()\n";
        //Game::sem()->p();
        Thread::yield();
        //Game::sem()->v();
    }
}

PlayerShip::PlayerShip(int x, int y) {
    _health = 3;
    _direction = UP;
    _speed = 10;
    //* meio da tela
    _x = x;
    _y = y;
}

PlayerShip::~PlayerShip() {
    //
}

//retorna True se a nave morrer
bool PlayerShip::lose_life() {
    /*ideias:
    -piscar o sprite
    -ficar invulneravel durante 1 segundo*/
    if (_health > 1) {
        _health--;
        return 0;
    } else {
        //matar a nave
        //deletar a thread
        return 1;
    }
}

unsigned int PlayerShip::health() {
    return _health;
}

__END_API