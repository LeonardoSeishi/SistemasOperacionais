#include "../include/spaceship.h"
//PLAYER

__BEGIN_API

void PlayerShip::runPlayerShip() {
    std::cout << "Chegou no run playership\n";
    while (Game::isWindowOpen()) {
        Game::sem()->p();
        Thread::yield();
        Game::sem()->v();
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
    //*/
    sf::Texture* texture = getTexture();
    sf::Sprite* sprite = getSprite();
    texture->loadFromFile("sprites/space_ships/space_ship1.png");
    sprite->setTexture(*texture);
    sprite->scale(-0.5, -0.5);
    sprite->setPosition(_x, _y);

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