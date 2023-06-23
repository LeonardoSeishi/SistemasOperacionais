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
private:
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

public:

    static int do_work(int n)
    {
        int i, j, soma;

        soma = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                {soma += j * i;}
        return soma;
        }
    }

    Game();

    ~Game();

    void kill();

    void restart();

    void pause();

    void update();

    void endGame();

    void startGame();

    static void init(void *name);

    //gets e sets
    static bool isWindowOpen();
    static Semaphore* sem();

    static bool paused();
    static unsigned int getSpeed();
    static unsigned int getScore();
    static unsigned int getEliminations();

private:
    static Semaphore *_game_sem;

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

    static bool _windowOpen;
    static bool _paused;
    static unsigned int _level;
    static unsigned int _speed;
    // scoreboard
    static unsigned int _eliminations;
    static unsigned int _score;

    // acho que nao precisa, mas vou deixar anotado aqui para lembrar
    // highscore json
    // pegar os dados salvos
    // unsigned int highscore;
};

__END_API
#endif

