#ifndef game_entity_h
#define game_entity_h

class GameEntity 
{
public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    //gets e sets
    unsigned int speed();
    unsigned int x();
    unsigned int y();
    Direction direction();

    void set_position(unsigned int x, unsigned int y);

//Declaracao dos atributos de uma entidade  
protected:
    unsigned int _speed;
    volatile Direction _direction;

    //posicao
    unsigned int _x;
    unsigned int _y;
};

#endif