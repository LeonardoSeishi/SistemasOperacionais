#ifndef game_h
#define game_h

#include "window.h"

class Game
{
private:
    unsigned int _level;
    unsigned int _speed;

    //scoreboard
    unsigned int _eliminations;
    unsigned int _score;

    //acho que nao precisa, mas vou deixar anotado aqui para lembrar
    //highscore json
    //pegar os dados salvos
    //unsigned int highscore;

public:
    Game(/* args */);

    ~Game();

    void kill();

    void restart();

    //gets e sets
    unsigned int speed();
    unsigned int score();
    unsigned int eliminations();
};


#endif

