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
    //temos que fazer algum jeito para ele saber que o jogo esta rodando
    //para poder receber os input
    //sem usar a classe window
    //while (window.isOpen()) { 
}

PlayerShip::PlayerShip(int x, int y) {
    _health = 3;
    _direction = UP;
    _speed = 10;
    //* meio da tela
    _x = x;
    _y = y;
    std::cout << "PlayerShip construtor 1\n";
    getTexture().loadFromFile("sprites/space_ships/space_ship1.png");

    std::cout << "PlayerShip construtor 2\n";
    getSprite().setTexture(_shipTexture);
    
    std::cout << "PlayerShip construtor 3\n";
    getSprite().scale(0.5, 0.5);
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