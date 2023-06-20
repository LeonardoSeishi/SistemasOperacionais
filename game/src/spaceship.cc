#include "../include/spaceship.h"

__BEGIN_API


void Spaceship::move(Spaceship::Direction direction) {
    unsigned int new_x = x();
    unsigned int new_y = y();

    switch (direction) {
        case UP:
            new_y -= speed();
            _direction = UP;
            break;
        case DOWN:
            new_y += speed();
            _direction = DOWN;
            break;
        case LEFT:
            new_x -= speed();
            _direction = LEFT;
            break;
        case RIGHT:
            new_x += speed();
            _direction = RIGHT;
            break;
    }

    set_position(new_x, new_y);
    sf::Sprite *sprite = getSprite();
    sprite->setPosition(new_x, new_y);
}

void Spaceship::shoot() {
    unsigned int projectile_x = x();
    unsigned int projectile_y = y();
    Direction projectile_direction = direction();
}

sf::Sprite* Spaceship::getSprite() {
    return shipSprite;
}

sf::Texture* Spaceship::getTexture() {
    return shipTexture;
}

//PLAYER

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