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

    virtual ~GameEntity();

    virtual void move(GameEntity::Direction direction);//, sf::Sprite &sprite);
    virtual void sem_lock();
    //gets e sets
    virtual unsigned int speed();
    virtual unsigned int x();
    virtual unsigned int y();
    virtual Direction direction();
    virtual sf::Sprite& getSprite();

    virtual void set_position(unsigned int x, unsigned int y);
    virtual void draw_entity(sf::Sprite &sprite, float rotation, float x, float y);

//Declaracao dos atributos de uma entidade  
protected:
    unsigned int _speed;
    volatile Direction _direction;
    unsigned int _health;

    //posicao
    unsigned int _x;
    unsigned int _y;

    sf::Sprite _entity_sprite;
    Semaphore *_sem;
    // sf::Texture _shipTexture;
};

__END_API

#endif