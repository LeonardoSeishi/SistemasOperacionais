#include "../include/projectile.h"

__BEGIN_API

Projectile::Projectile(unsigned int x, unsigned int y, Direction direction) {
    _speed = 10;
    _x = x;
    _y = y;
    _direction = direction;
}

void Projectile::runProjectile() {
    std::cout << "Chegou no run playership\n";

    while (Game::isWindowOpen()) {
        Projectile::move(direction(),GameWindow::get_shot_sprite());
        Thread::yield();
    }

}

bool Projectile::isEnemyShot() {
    return _enemy;
}

__END_API