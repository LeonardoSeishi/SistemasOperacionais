#ifndef projectile_h
#define projectile_h

#include "game_entity.h"

__BEGIN_API

class Projectile: public GameEntity
{
public:
    Projectile(unsigned int x, unsigned int y, Direction direction);

    ~Projectile();

    void runProjectile();

    //gets
    bool isEnemyShot();

    const sf::Sprite& getSprite() const;

private:
    //verifica se tiro é inimigo
    bool _enemy;

};

__END_API

#endif