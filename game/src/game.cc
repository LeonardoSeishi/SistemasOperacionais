#include "../include/game.h"

__BEGIN_API
//threads
Thread * Game::_window_thread;
Thread * Game::_player_thread;
Thread * Game::_enemy_thread;
Thread * Game::_input_thread;
//Thread * Game::_
//Thread * Game::

//classes
Semaphore * Game::_game_sem;
GameWindow * Game::_game_window;
PlayerShip * Game::_player_obj;
EnemyShip * Game::_enemy_obj;
Input * Game::_input_obj;
//

bool Game::_windowOpen;
bool Game::_paused;
unsigned int Game::_level;
unsigned int Game::_speed;
unsigned int Game::_eliminations;
unsigned int Game::_score;

Game::Game()
{
    _windowOpen = true;
    _paused = false;
    _level = 1;
    _speed = 10;
    _eliminations = 0;
    _score = 0;

}

Game::~Game() {}

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

bool Game::isWindowOpen() {
    return _windowOpen;
}

Semaphore * Game::sem(){
    return _game_sem;
}

void Game::startGame() {
    // Inicializa threads do jogo
    // Thread *_window = new Thread(GameWindow::run, game->game_window);
    // _window_thread = new Thread(GameWindow::run);
}

void Game::init(void *name) {
    //_game_window = new GameWindow();
    //GameWindow::init();
    //GameWindow::run();
    _game_sem = new Semaphore(1);

    _window_thread = new Thread(windowRun);
    _player_thread = new Thread(playerRun);

    do_work(20000);

    int ec;
    std::cout << "main: esperando window_thread...\n";
    ec = _window_thread->join();
    std::cout << "main: window_thread acabou com exit code " << ec << "\n";

    std::cout << "main: esperando player_thread...\n";
    ec = _player_thread->join();
    std::cout << "main: player_thread acabou com exit code " << ec << "\n";

    delete _game_sem;

    delete _window_thread;
    delete _player_thread;
    
    
}

void Game::windowRun() {
    _game_window = new GameWindow();
    _game_window->run();
    _windowOpen = false;
    delete _game_window;
    _window_thread->thread_exit(2);

}

void Game::playerRun() {
    _player_obj = new PlayerShip(240,240);

    std::cout << "criou o _player_obj\n";
    
    _player_obj->runPlayerShip();
    delete _player_obj;
    _player_thread->thread_exit(3);
}

//void Game::enemyRun

//void Game::shotRun

//void Game::inputRun

//gets e sets
bool Game::paused() { return _paused;}
unsigned int Game::getSpeed() {return _speed;}
unsigned int Game::getScore() {return _score;}
unsigned int Game::getEliminations() {return _eliminations;}

__END_API