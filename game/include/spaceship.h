#ifndef spaceship_h
#define spaceship_h

#include "projectile.h"
#include "game.h"
#include "game_entity.h"


__BEGIN_API

class Spaceship: public GameEntity
{
public:

    void shoot();

    void move(GameEntity::Direction direction) override;

    void sem_lock() override;
    unsigned int speed() override;
    unsigned int x() override;
    unsigned int y() override;
    Direction direction() override;

    sf::Sprite &getSprite() override;

    void set_position(unsigned int x, unsigned int y) override;

    void draw_entity(sf::Sprite &sprite, float rotation, float x, float y) override;
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
    
};

__END_API

#endif
