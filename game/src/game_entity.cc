#include "../include/game_entity.h"

//gets e sets

__BEGIN_API

void GameEntity::move(Direction direction, sf::Sprite &sprite)
{
    unsigned int new_x = x();
    unsigned int new_y = y();
    // Speed pode ser o numero de vezes que inimigos se movimentam antes de player
    switch (direction) {
        case UP:
            new_y -= speed();
            _direction = UP;
            GameWindow::draw_entity(sprite, 0, new_x, new_y);
            break;
        case DOWN:
            new_y += speed();
            _direction = DOWN;
            GameWindow::draw_entity(sprite, 180, new_x, new_y);
            break;
        case LEFT:
            new_x -= speed();
            _direction = LEFT;
            GameWindow::draw_entity(sprite, 270, new_x, new_y);
            break;
        case RIGHT:
            new_x += speed();
            _direction = RIGHT;
            GameWindow::draw_entity(sprite, 90, new_x, new_y);
            break;
    }
    set_position(new_x, new_y);
}

unsigned int GameEntity::speed() {return _speed;}

unsigned int GameEntity::x() {return _x;}

unsigned int GameEntity::y() {return _y;}

GameEntity::Direction GameEntity::direction() {return _direction;} 

void GameEntity::set_position(unsigned int x, unsigned int y){
    _x = x;
    _y = y;
}


__END_API
// sf::Sprite& GameEntity::getSprite() {
//     return _shipSprite;
// }

// sf::Texture& GameEntity::getTexture() {
//     return _shipTexture;
// }