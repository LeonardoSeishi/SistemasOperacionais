#ifndef projectile_h
#define projectile_h

#include "game_entity.h"

class Projectile: public GameEntity
{
public:
    Projectile();

    ~Projectile();

    void runProjectile();

    //gets
    bool isEnemyShot();

private:
    //verifica se tiro é inimigo
    bool _enemy;

};

#endif