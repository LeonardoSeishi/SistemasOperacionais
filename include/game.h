#ifndef game_h
#define game_h

#include "window.h"

class Game
{
private:
    bool _paused;

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
    Game(int level) {
    _paused = false;

    _level = level;
    //provisorio
    switch (_level) {
    case 3:
        _speed = 30;
    case 2:
        _speed = 20;
    case 1:
        _speed = 10;
    }

    _eliminations = 0;
    _score = 0;
    }

    ~Game();

    void kill();

    void restart();

    void pause();

    //gets e sets
    bool paused();
    unsigned int speed();
    unsigned int score();
    unsigned int eliminations();
};


#endif

