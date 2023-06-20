#ifndef spaceship_h
#define spaceship_h

#include "game_entity.h"
#include "window.h"
#include <SFML/Graphics.hpp>


class Spaceship: public GameEntity
{
public:

    void move_up();

    void move_down();
    
    void move_left();
    
    void move_right();

    void shoot();

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

    //funcao o qual a thread ira rodar
    void runEnemyShip();

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

    void runPlayerShip();

    bool lose_life();

    unsigned int health();

private:
    unsigned int _health;

};



#endif
