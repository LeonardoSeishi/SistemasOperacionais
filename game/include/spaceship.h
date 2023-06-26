#ifndef spaceship_h
#define spaceship_h

#include <SFML/Graphics.hpp>
#include "../../thread/include/traits.h"
#include "../../thread/include/semaphore.h"
#include "game_entity.h"


__BEGIN_API

class Spaceship: public GameEntity
{
public:

    void shoot();

    //const sf::Sprite& getSprite() const;
};


class EnemyShip: public Spaceship 
{
public:
    EnemyShip(unsigned int x, unsigned int y, unsigned int speed);

    ~EnemyShip();

    void lose_life();

    // Roda algoritmo
    static void runEnemyShip(EnemyShip *enemy, int algoritmo);

private:
    int _dificult;

};

class PlayerShip: public Spaceship 
{
public:
    PlayerShip(int x, int y);

    ~PlayerShip();

    // Monitora vida e atira
    static void runPlayerShip(PlayerShip *player);

    bool lose_life();

    unsigned int health();

private:
    unsigned int _health;

};

__END_API

#endif
