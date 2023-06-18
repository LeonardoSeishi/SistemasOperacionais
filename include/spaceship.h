#ifndef spaceship_h
#define spaceship_h

#include "window.h"
#include <SFML/Graphics.hpp>


class Spaceship 
{
public:

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    void move_up();

    void move_down();
    
    void move_left();
    
    void move_right();

    void shoot();

    //gets e sets
    unsigned int health();
    unsigned int speed();
    unsigned int x();
    unsigned int y();
    Direction direction();

    void set_position(unsigned int x, unsigned int y);

//Declaracao dos atributos da nave   
protected:
    unsigned int _speed;
    volatile Direction _direction;

    //posicao
    unsigned int _x;
    unsigned int _y;
};


class EnemyShip: public Spaceship 
{
public:
    EnemyShip(unsigned int x, unsigned int y, unsigned int speed){
        _x = x;
        _y = y;
        /*calcular a direction dependendo de qual parede ele ira surgir
        if (_y < 0 && _x > 0 && _x < parede_direita) {
            _direction = DOWN;
        } else if (_y > valor_chao && _x > 0 && _x < parede_direita) {
            _direction = UP;
        } else if ...
        */
       _speed = speed;
    }

    ~EnemyShip();

    void lose_life();

private:
    int _dificult;
/*  algoritmo de movimentacao???
*/
};

class PlayerShip: public Spaceship 
{
public:
    PlayerShip(int x, int y){
        _health = 3;
        _direction = UP;
        _speed = 10;
        //* meio da tela
        _x = x;
        _y = y;
        //*/
    }

    ~PlayerShip();

    bool lose_life();

    unsigned int health();

private:
    unsigned int _health;

};



#endif
