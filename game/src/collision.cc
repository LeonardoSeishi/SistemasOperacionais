#include "../include/collision.h"

__BEGIN_API

bool Collision::checkCollision(const Spaceship& spaceship, const Projectile& projectile) {
   // sf::FloatRect spaceshipBounds = spaceship.getSprite().getGlobalBounds();
   // sf::FloatRect projectileBounds = projectile.getSprite().getGlobalBounds();

    //return spaceshipBounds.intersects(projectileBounds);
}

void Collision::handleCollisions(PlayerShip& player, const std::vector<EnemyShip*>& enemies, std::vector<Projectile*>& projectiles) {
    for (auto& enemy : enemies) {
        for (auto& projectile : projectiles) {
            bool enemyShot = projectile->isEnemyShot();

            if (!enemyShot && checkCollision(*enemy, *projectile)) {
                enemy->lose_life();
            }
            if (enemyShot && checkCollision(player, *projectile)) {
                player.lose_life();
            }
        }
    }
}

__END_API
