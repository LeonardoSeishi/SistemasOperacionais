#include "../include/spaceship.h"

__BEGIN_API


void Spaceship::shoot() {

    _shot_obj = new Projectile(x(),y(),direction());
    _shot_thread = new Thread(Projectile::runProjectile, _shot_obj);
    _shot_obj->Projectile::set_thread(_shot_thread);
    
    _shot_thread->join();

    delete _shot_obj;
    delete _shot_thread;
}


void Spaceship::sem_lock() {
    std::cout << "lock sem spaceship\n";
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

void Spaceship::set_direction(GameEntity::Direction direction)
{
    _direction = direction;
}

sf::Sprite& Spaceship::getSprite() {
    return _entity_sprite;
}

sf::Texture& Spaceship::getTexture() {
    return _entity_texture;
}

unsigned int Spaceship::get_health() {
    return _health;
}

void Spaceship::lose_health() {
    _health--;
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

}

void Spaceship::move(GameEntity::Direction direction)
{
    unsigned int new_x = x();
    unsigned int new_y = y();

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