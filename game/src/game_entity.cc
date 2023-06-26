#include "../include/game_entity.h"

//gets e sets

unsigned int GameEntity::speed() {return _speed;}

unsigned int GameEntity::x() {return _x;}

unsigned int GameEntity::y() {return _y;}

GameEntity::Direction GameEntity::direction() {return _direction;} 

void GameEntity::set_position(unsigned int x, unsigned int y){
    _x = x;
    _y = y;
}

void GameEntity::draw_entity(sf::Sprite &sprite, float rotation, float x, float y)
{
    sprite.setPosition(x, y);
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width/2, bounds.height/2);
    sprite.setRotation(rotation);
}

// sf::Sprite& GameEntity::getSprite() {
//     return _shipSprite;
// }

// sf::Texture& GameEntity::getTexture() {
//     return _shipTexture;
// }