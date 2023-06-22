#ifndef game_h
#define game_h

#include "../../thread/include/traits.h"
#include "window.h"
#include "spaceship.h"
#include "input.h"
#include "semaphore.h"

__BEGIN_API

class Game
{

public:
    Game();

    ~Game();

    void kill();

    void restart();

    void pause();

    void update();

    void endGame();

    void startGame();

    //gets e sets
    bool paused();
    unsigned int getSpeed();
    unsigned int getScore();
    unsigned int getEliminations();

private:
    Semaphore *_game_sem;

    // Classes de threads
    GameWindow* _game_window;
    Input *_input_obj;
    PlayerShip *_player_obj;
    EnemyShip *_enemy_1;
    EnemyShip *_enemy_2;
    EnemyShip *_enemy_3;
    EnemyShip *_enemy_4;



    bool _paused;
    unsigned int _level;
    unsigned int _speed;
    // scoreboard
    unsigned int _eliminations;
    unsigned int _score;

    // acho que nao precisa, mas vou deixar anotado aqui para lembrar
    // highscore json
    // pegar os dados salvos
    // unsigned int highscore;
};

__END_API
#endif

