#include "../include/game.h"

__BEGIN_API

Game::Game()
{
    _paused = false;
    level = 1;
    speed = 10;
    eliminations = 0;
    score = 0;

    game_sem = new Semaphore(1);
    // game_window = new GameWindow();
    // player_obj = new PlayerShip(220, 365);
    // input_obj = new Input(player_obj);
    // enemy_1 = new EnemyShip(245, 150, 0);
    // enemy_2 = new EnemyShip(245, 155, 0);
    // enemy_3 = new EnemyShip(245, 160, 0);
    // enemy_4 = new EnemyShip(245, 165, 0);
}

Game::~Game() {
    delete game_sem;
    // delete game_window;
    delete input_obj;
    delete player_obj;
    delete enemy_1;
    delete enemy_2;
    delete enemy_3;
    delete enemy_4;
}

void Game::kill(/**/) { //passar nave inimiga como parameto para destruila???
    //delete EnemyShip
    score = getScore() + 100;

    if (getSpeed() < 3)
    { // checar se nao esta na velocidade maxima
        if (getEliminations() < 4)
        {
            speed = getSpeed() + 1;   //aumenta a velocidade do jogo
            eliminations = 0;      //reseta a contagem
        }
        else
        {
            eliminations = getEliminations() + 1;
        }
    }
}

void Game::restart() {
    score = 0;
    speed = 1;
    eliminations = 0;
    _paused = false;
    //outras coisas
}

void Game::pause() {
    if (paused()) {
        _paused = false;
    } else {
        _paused = true;
    }
}

void Game::update() {
    return;
}

void Game::endGame() {
    return;
}

void Game::startGame() {
    // Inicializa threads do jogo
    // Thread *_window = new Thread(GameWindow::run, game->game_window);
    // _window_thread = new Thread(GameWindow::run);
}

void Game::init(void *name) {
    GameWindow *_window = new GameWindow();
    GameWindow::init();
    GameWindow::run();
    // Thread *_twindow = new Thread(GameWindow::run);
}

//gets e sets
bool Game::paused() { return _paused;}
unsigned int Game::getSpeed() {return speed;}
unsigned int Game::getScore() {return score;}
unsigned int Game::getEliminations() {return eliminations;}

__END_API