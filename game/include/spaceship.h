#ifndef spaceship_h
#define spaceship_h

#include <SFML/Graphics.hpp>
#include "game_entity.h"
#include "window.h"
#include "../../thread/include/traits.h"
#include "../../thread/include/semaphore.h"

__BEGIN_API

class Spaceship: public GameEntity
{
public:

    void move(GameEntity::Direction);

    void shoot();
};


class EnemyShip: public Spaceship 
{
public:
    EnemyShip(unsigned int x, unsigned int y, unsigned int speed);

    ~EnemyShip();

    //funcao o qual a thread ira rodar
    void runEnemyShip();

    void lose_life();

private:
    int _dificult;
/*  algoritmo de movimentacao???
*/
};

class PlayerShip: public Spaceship 
{
public:
    PlayerShip(int x, int y);

    ~PlayerShip();

    void runPlayerShip();

    bool lose_life();

    unsigned int health();

private:
    unsigned int _health;

};

__END_API

#endif
