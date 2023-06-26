#ifndef game_entity_h
#define game_entity_h

#include <SFML/Graphics.hpp>
#include "../../thread/include/traits.h"
#include "../../thread/include/semaphore.h"

__BEGIN_API

class GameEntity 
{
public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    void move(GameEntity::Direction, sf::Sprite &sprite);

    //gets e sets
    unsigned int speed();
    unsigned int x();
    unsigned int y();
    Direction direction();

    // sf::Sprite& getSprite();

    // sf::Texture& getTexture();

    void set_position(unsigned int x, unsigned int y);
    void draw_entity(sf::Sprite &sprite, float rotation, float x, float y);

//Declaracao dos atributos de uma entidade  
protected:
    unsigned int _speed;
    volatile Direction _direction;

    //posicao
    unsigned int _x;
    unsigned int _y;

    // sf::Sprite _shipSprite;
    // sf::Texture _shipTexture;
};

__END_API

#endif