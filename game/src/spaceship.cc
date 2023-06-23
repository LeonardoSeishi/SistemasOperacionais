#include "../include/spaceship.h"

__BEGIN_API


void Spaceship::move(Spaceship::Direction direction) {
    unsigned int new_x = x();
    unsigned int new_y = y();

    switch (direction) {
        case UP:
            new_y -= speed();
            _direction = UP;
            break;
        case DOWN:
            new_y += speed();
            _direction = DOWN;
            break;
        case LEFT:
            new_x -= speed();
            _direction = LEFT;
            break;
        case RIGHT:
            new_x += speed();
            _direction = RIGHT;
            break;
    }

    set_position(new_x, new_y);
    sf::Sprite *sprite = getSprite();
    sprite->setPosition(new_x, new_y);
}

void Spaceship::shoot() {
    unsigned int projectile_x = x();
    unsigned int projectile_y = y();
    Direction projectile_direction = direction();
}

__END_API