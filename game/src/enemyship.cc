#include "../include/spaceship.h"

__BEGIN_API

// ENEMY
EnemyShip::EnemyShip(unsigned int x, unsigned int y, unsigned int speed)
{
    _x = x;
    _y = y;
    _speed = speed;

    // calcular a direction dependendo de qual parede ele ira surgir
    // 705 = parede_direita
    // 685 = valor_chao
    if (_y < 0 && _x > 0 && _x < 705)
    {
        _direction = DOWN;
    }
    else if (_y > 685 && _x > 0 && _x < 705)
    {
        _direction = UP;
    }
    // else if (_y > 685 && _x > 0 && _x < 705) {
    //     _direction = UP;
    // }
    // else if (_y > 685 && _x > 0 && _x < 705) {
    //     _direction = UP;
    // }
}

EnemyShip::~EnemyShip() {}

void EnemyShip::lose_life()
{
    // morrer
    // suspender a thread por 2 segundos
}

void EnemyShip::runEnemyShip(EnemyShip *enemy, int algoritmo)
{
    std::cout << "Chegou no run enemyship\n";

    while (Game::isWindowOpen())
    {
        
        Thread::yield();

    }
}

__END_API