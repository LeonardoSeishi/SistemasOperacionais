#include "../include/game.h"

__BEGIN_API

Game::Game()
{
    _paused = false;
    _level = 1;
    _speed = 10;
    _eliminations = 0;
    _score = 0;

    _game_sem = new Semaphore(1);
    _game_window = new GameWindow();
    _player_obj = new PlayerShip(220, 365);
    _input_obj = new Input(_player_obj);
    _enemy_1 = new EnemyShip(245, 150, 0);
    _enemy_2 = new EnemyShip(245, 155, 0);
    _enemy_3 = new EnemyShip(245, 160, 0);
    _enemy_4 = new EnemyShip(245, 165, 0);
}

Game::~Game() {
    delete _game_sem;
    delete _game_window;
    delete _input_obj;
    delete _player_obj;
    delete _enemy_1;
    delete _enemy_2;
    delete _enemy_3;
    delete _enemy_4;
}

void Game::kill(/**/) { //passar nave inimiga como parameto para destruila???
    //delete EnemyShip
    _score = getScore() + 100;

    if (getSpeed() < 3)
    { // checar se nao esta na velocidade maxima
        if (getEliminations() < 4)
        {
            _speed = getSpeed() + 1;   //aumenta a velocidade do jogo
            _eliminations = 0;      //reseta a contagem
        }
        else
        {
            _eliminations = getEliminations() + 1;
        }
    }
}

void Game::restart() {
    _score = 0;
    _speed = 1;
    _eliminations = 0;
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
    GameWindow::init();
    // Inicializa threads do jogo
}

//gets e sets
bool Game::paused() { return _paused;}
unsigned int Game::getSpeed() {return _speed;}
unsigned int Game::getScore() {return _score;}
unsigned int Game::getEliminations() {return _eliminations;}

__END_API