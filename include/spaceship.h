#ifndef spaceship_h
#define spaceship_h

#include "thread.h"
#include "semaphore.h"

__BEGIN_API

class Spaceship 
{
public:

    void move_up();

    void move_down();
    
    void move_left();
    
    void move_right();

    void shoot();

    void lose_life();

    //gets e sets
    unsigned int health() {
        return _health;
    }

    unsigned int speed() {
        return _speed;
    }

    unsigned int x(){
        return _x;
    }

    unsigned int y(){
        return _y;
    }

    void set_position(unsigned int x, unsigned int y);

//Declaracao dos atributos da nave   
protected:
    unsigned int _health;
    unsigned int _speed;

    //posicao
    unsigned int _x;
    unsigned int _y;
};

class EnemyShip: public Spaceship 
{
public:
    EnemyShip();

    ~EnemyShip();

};

class PlayerShip: public Spaceship 
{
public:
    PlayerShip();

    ~PlayerShip();

};



__END_API


#endif
