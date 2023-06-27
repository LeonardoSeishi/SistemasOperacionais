#include "../include/spaceship.h"

__BEGIN_API

void Spaceship::shoot() {
    unsigned int projectile_x = x();
    unsigned int projectile_y = y();
    Direction projectile_direction = direction();
}

void Spaceship::sem_lock() {
    std::cout << "vai tomar no cu\n";
}

unsigned int Spaceship::speed() {
    return _speed;
}

unsigned int Spaceship::x() {
    return _x;
}

unsigned int Spaceship::y()
{
    return _y;
}

GameEntity::Direction Spaceship::direction() {
    return _direction;
}

sf::Sprite& Spaceship::getSprite() {
    return _entity_sprite;
}

void Spaceship::set_position(unsigned int x, unsigned int y) {
    _x = x;
    _y = y;
}

void Spaceship::draw_entity(sf::Sprite &sprite, float rotation, float x, float y) {
    sprite.setPosition(x, y);
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    sprite.setRotation(rotation);
    // GameWindow::draw_sprite(sprite);
}

void Spaceship::move(GameEntity::Direction direction)
{
    unsigned int new_x = x();
    unsigned int new_y = y();
    // Speed pode ser o numero de vezes que inimigos se movimentam antes de player
    switch (direction)
    {
    case UP:
        new_y -= speed();
        _direction = UP;
        draw_entity(_entity_sprite, 0, new_x, new_y);
        break;
    case DOWN:
        new_y += speed();
        _direction = DOWN;
        draw_entity(_entity_sprite, 180, new_x, new_y);
        break;
    case LEFT:
        new_x -= speed();
        _direction = LEFT;
        draw_entity(_entity_sprite, 270, new_x, new_y);
        break;
    case RIGHT:
        new_x += speed();
        _direction = RIGHT;
        draw_entity(_entity_sprite, 90, new_x, new_y);
        break;
    }
    set_position(new_x, new_y);
}

__END_API