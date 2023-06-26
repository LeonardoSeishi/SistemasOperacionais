#ifndef collision_h
#define collision_h

#include <SFML/Graphics.hpp>
#include <vector>
#include "game.h"

__BEGIN_API

class Collision
{
public:
    static bool checkCollision(const Spaceship &spaceship, const Projectile &projectile);
    static void handleCollisions(PlayerShip &player, const std::vector<EnemyShip *> &enemies, std::vector<Projectile *> &projectiles);
};

__END_API
#endif

