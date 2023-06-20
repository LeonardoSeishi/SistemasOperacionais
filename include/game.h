#ifndef game_h
#define game_h

#include "traits.h"
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


    //gets e sets
    bool paused();
    unsigned int getSpeed();
    unsigned int getScore();
    unsigned int getEliminations();

private:
    Semaphore *game_sem;
    // Classes de threads
    GameWindow* game_window;
    Input *input_obj;
    PlayerShip *player_obj;
    EnemyShip *enemy_1;
    EnemyShip *enemy_2;
    EnemyShip *enemy_3;
    EnemyShip *enemy_4;

    bool _paused;
    unsigned int level;
    unsigned int speed;
    // scoreboard
    unsigned int eliminations;
    unsigned int score;

    // acho que nao precisa, mas vou deixar anotado aqui para lembrar
    // highscore json
    // pegar os dados salvos
    // unsigned int highscore;
};

__END_API
#endif

