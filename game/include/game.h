#ifndef game_h
#define game_h

#include "../../thread/include/traits.h"
#include "../../thread/include/thread.h"
#include "../../thread/include/semaphore.h"
#include "spaceship.h"
#include "input.h"

#include <vector>


__BEGIN_API

class Game
{
// private:
//     static void windowRun();
//     static void playerRun(PlayerShip *player_obj);
//     static void enemyRun();
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
    static bool closeWindow() {_windowOpen = false;}
    static Semaphore* sem();
    static GameWindow& getWindow() { return *_game_window; }
    // static PlayerShip getPlayer() { return *_player; }
    // static EnemyShip getEnemy1() { return *_enemy_1; }
    // static EnemyShip getEnemy2() { return *_enemy_2; }
    // static EnemyShip getEnemy3() { return *_enemy_3; }
    // static EnemyShip getEnemy4() { return *_enemy_4; }

    static void addEnemy(sf::Sprite& enemy);
    static std::vector<sf::Sprite>& getEnemies();

    static bool paused();
    static unsigned int getSpeed();
    static unsigned int getScore();
    static unsigned int getEliminations();
    // Passar pra cc
    // static GameWindow& getWindow() { return *_game_window; }

private:
    static Semaphore *_game_sem;

    // Classes de threads
    static GameWindow* _game_window;
    static Input *_input_obj;
    static PlayerShip *_player;
    static EnemyShip *_enemy_1;
    static EnemyShip *_enemy_2;
    static EnemyShip *_enemy_3;
    static EnemyShip *_enemy_4;

    //threads 
    static Thread * _window_thread;
    static Thread * _input_thread;
    static Thread * _player_thread;
    static Thread * _enemy_1_thread;
    static Thread * _enemy_2_thread;
    static Thread * _enemy_3_thread;
    static Thread * _enemy_4_thread;

    static std::vector<EnemyShip*> _enemies;

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

