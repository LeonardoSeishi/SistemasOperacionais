#include "../include/spaceship.h"

__BEGIN_API


//ENEMY
EnemyShip::EnemyShip(unsigned int x, unsigned int y, unsigned int speed) {
    _x = x;
    _y = y;
    /*calcular a direction dependendo de qual parede ele ira surgir
    if (_y < 0 && _x > 0 && _x < parede_direita) {
        _direction = DOWN;
    } else if (_y > valor_chao && _x > 0 && _x < parede_direita) {
        _direction = UP;
    } else if ...
    */
    _speed = speed;
    sf::Texture *texture = getTexture();
    sf::Sprite *sprite = getSprite();
    texture->loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    sprite->setTexture(*texture);
    sprite->scale(-0.5, -0.5);
    sprite->setPosition(_x, _y);
}

EnemyShip::~EnemyShip() {}

void EnemyShip::lose_life() {
    //morrer
    //suspender a thread por 2 segundos
}

__END_API