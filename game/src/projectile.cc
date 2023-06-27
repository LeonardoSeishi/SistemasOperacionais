#include "../include/projectile.h"

__BEGIN_API

Projectile::Projectile(unsigned int x, unsigned int y, Direction direction) {
    _speed = 1;
    _x = x;
    _y = y;
    _health = 1;
    _direction = direction;

    getTexture().loadFromFile("sprites/space_ships/shot.png");
    getSprite().setTexture(getTexture());
    getSprite().setPosition(x, y);
    getSprite().scale(0.5, 0.5);
}

bool Projectile::checkPositionBound() {
    // Da posição 10 a 705 no sentido horizontal X
    // Da posição 10 a 685 no sentido vertical Y
    if ((_x > 10 && _x < 705 && _y > 10 && _y < 685)) {
        return true;
    } else {
        return false;
    }
}

Projectile::~Projectile() {

}

void Projectile::set_thread(Thread * thread) {
    shot_thread = thread;
}

Thread * Projectile::get_thread() {
    return shot_thread;
}

void Projectile::runProjectile(Projectile *shot) {

    while (Game::isWindowOpen()) {
        shot->move(shot->direction());
        GameWindow::draw_sprite(shot->getSprite());
        if (shot->get_health() < 1) {
            //colisao
            break;
        } else if (!shot->checkPositionBound()) {
            break;
            //saiu da tela
        }
        Thread::yield();
    }
    shot->get_thread()->thread_exit(10);
}


//////////////////// Game Entity //////////////////////////

void Projectile::move(GameEntity::Direction direction)
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

void Projectile::sem_lock() {
    std::cout << "sem_lock\n";
}

unsigned int Projectile::speed() {
    return _speed;
}

unsigned int Projectile::x() {
    return _x;
}

unsigned int Projectile::y()
{
    return _y;
}

GameEntity::Direction Projectile::direction() {
    return _direction;
}

void Projectile::set_direction(GameEntity::Direction direction){
    _direction = direction;
}

unsigned int Projectile::get_health() {
    return _health;
}

void Projectile::lose_health() {
    _health--;
}


sf::Sprite& Projectile::getSprite() {
    return _entity_sprite;
}

sf::Texture& Projectile::getTexture(){
    return _entity_texture;
}

void Projectile::set_position(unsigned int x, unsigned int y) {
    _x = x;
    _y = y;
}

void Projectile::draw_entity(sf::Sprite &sprite, float rotation, float x, float y) {
    sprite.setPosition(x, y);
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    sprite.setRotation(rotation);

}



__END_API