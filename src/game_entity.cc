#include "../include/game_entity.h"

//gets e sets

unsigned int GameEntity::speed() {return _speed;}

unsigned int GameEntity::x() {return _x;}

unsigned int GameEntity::y() {return _y;}

GameEntity::Direction GameEntity::direction() {return _direction;} 

void GameEntity::set_position(unsigned int x, unsigned int y){
    _x = x;
    _y = y;
}