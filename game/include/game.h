#ifndef game_h
#define game_h

#include "../../thread/include/traits.h"
#include "../../thread/include/thread.h"
#include "../../thread/include/semaphore.h"
#include "window.h"
#include "spaceship.h"
#include "input.h"


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

    static void init(void *name);

    static void windowRun();
    static void playerRun();
    static void enemyRun();
    /*
    static void Run();
    static void Run();
    static void Run();
    static void Run();
    static void Run();
    */

    //gets e sets
    bool paused();
    unsigned int getSpeed();
    unsigned int getScore();
    unsigned int getEliminations();

private:
    //static Semaphore *_game_sem;

    // Classes de threads
    static GameWindow* _game_window;
    static Input *_input_obj;
    static PlayerShip *_player_obj;
    static EnemyShip *_enemy_obj;
    static EnemyShip *_enemy_1;
    static EnemyShip *_enemy_2;
    static EnemyShip *_enemy_3;
    static EnemyShip *_enemy_4;

    //threads 
    static Thread * _window_thread;
    static Thread * _input_thread;
    static Thread * _player_thread;
    static Thread * _enemy_thread;
    /*static Thread * 
    static Thread * 
    static Thread * 
    */

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

