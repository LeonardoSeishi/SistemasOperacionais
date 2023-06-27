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

    virtual void move(GameEntity::Direction direction) =0;//, sf::Sprite &sprite);
    virtual void sem_lock() =0;
    //gets e sets
    virtual unsigned int speed() =0;
    virtual unsigned int x()=0;
    virtual unsigned int y()=0;
    virtual sf::Sprite& getSprite()=0;
    virtual sf::Texture& getTexture()=0;
    virtual unsigned int get_health()=0;
    virtual void lose_health()=0;

    virtual Direction direction()=0;
    virtual void set_direction(GameEntity::Direction direction)=0;

    virtual void set_position(unsigned int x, unsigned int y)=0;
    virtual void draw_entity(sf::Sprite &sprite, float rotation, float x, float y)=0;

//Declaracao dos atributos de uma entidade  
protected:
    unsigned int _speed;
    volatile Direction _direction;
    unsigned int _health;

    //posicao
    unsigned int _x;
    unsigned int _y;

    sf::Sprite _entity_sprite;
    sf::Texture _entity_texture;
    Semaphore *_sem;
    // sf::Texture _shipTexture;
};

__END_API

#endif