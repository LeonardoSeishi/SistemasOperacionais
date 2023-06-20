#include "../include/spaceship.h"



void Spaceship::move_up() {
    unsigned int new_y = y() - speed();
    set_position(x(), new_y);
    _direction = UP;
}

void Spaceship::move_down() {
    unsigned int new_y = y() + speed();
    set_position(x(), new_y);
    _direction = DOWN;
}

void Spaceship::move_left() {
    unsigned int new_x = x() - speed();
    set_position(new_x, y());
    _direction = LEFT;
}

void Spaceship::move_right() {
    unsigned int new_x = x() + speed();
    set_position(new_x, y());
    _direction = RIGHT;
}

void Spaceship::shoot() {
    unsigned int projectile_x = x();
    unsigned int projectile_y = y();
    Direction projectile_direction = direction();
}

//PLAYER

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

void EnemyShip::lose_life() {
    //morrer
    //suspender a thread por 2 segundos
}