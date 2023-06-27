#include "../include/game.h"

__BEGIN_API

//Threads
Thread * Game::_window_thread;
Thread * Game::_player_thread;
Thread * Game::_enemy_1_thread;
Thread * Game::_enemy_2_thread;
Thread * Game::_enemy_3_thread;
Thread * Game::_enemy_4_thread;
Thread * Game::_input_thread;

//Classes
Semaphore * Game::_game_sem;
GameWindow * Game::_game_window;
PlayerShip * Game::_player;
EnemyShip * Game::_enemy_1;
EnemyShip * Game::_enemy_2;
EnemyShip * Game::_enemy_3;
EnemyShip * Game::_enemy_4;
Input * Game::_input_obj;

//Variáveis
bool Game::_windowOpen;
bool Game::_paused;
unsigned int Game::_level;
unsigned int Game::_speed;
unsigned int Game::_eliminations;
unsigned int Game::_score;

// std::vector<sf::Sprite> Game::_enemies;


Game::Game() {

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

void Game::init(void *name) {
    _windowOpen = true;
    _paused = false;
    _level = 1;
    _speed = 10;
    _eliminations = 0;
    _score = 0;

    _game_sem = new Semaphore(1);

    _game_window = new GameWindow();
    _player = new PlayerShip(380, 330);
    _enemy_1 = new EnemyShip(10, 10, 1, true);
    _enemy_2 = new EnemyShip(705, 10, 1, false);
    _enemy_3 = new EnemyShip(10, 685, 1, true);
    _enemy_4 = new EnemyShip(705, 685, 1, false);

    _input_obj = new Input(_player);

    _window_thread = new Thread(GameWindow::run, _game_window);
    _player_thread = new Thread(PlayerShip::runPlayerShip, _player);
    _enemy_1_thread = new Thread(EnemyShip::runEnemyShip, _enemy_1, 0);
    _enemy_2_thread = new Thread(EnemyShip::runEnemyShip, _enemy_2, 0);
    _enemy_3_thread = new Thread(EnemyShip::runEnemyShip, _enemy_3, 1);
    _enemy_4_thread = new Thread(EnemyShip::runEnemyShip, _enemy_4, 1);

    _input_thread = new Thread(Input::run);

    int ec;

    std::cout << "main: esperando player_thread...\n";
    ec = _player_thread->join();
    std::cout << "main: player_thread acabou com exit code " << ec << "\n";

    std::cout << "main: esperando enemy_1_thread...\n";
    ec = _enemy_1_thread->join();
    std::cout << "main: enemy_1_thread acabou com exit code " << ec << "\n";

    std::cout << "main: esperando enemy_2_thread...\n";
    ec = _enemy_2_thread->join();
    std::cout << "main: enemy_2_thread acabou com exit code " << ec << "\n";

    std::cout << "main: esperando enemy_3_thread...\n";
    ec = _enemy_3_thread->join();
    std::cout << "main: enemy_3_thread acabou com exit code " << ec << "\n";

    std::cout << "main: esperando enemy_4_thread...\n";
    ec = _enemy_4_thread->join();
    std::cout << "main: enemy_4_thread acabou com exit code " << ec << "\n";

    std::cout << "main: esperando window_thread...\n";
    ec = _window_thread->join();
    std::cout << "main: window_thread acabou com exit code " << ec << "\n";

    delete _game_sem;

    delete _player_thread;
    delete _enemy_1_thread;
    delete _enemy_2_thread;
    delete _enemy_3_thread;
    delete _enemy_4_thread;
    delete _window_thread;

    delete _input_thread;
    
}

// void Game::windowRun() {
// }

// void Game::playerRun(PlayerShip *player_obj) {
//     std::cout << "Dentro de playerRun em game.cc\n";
    
//     _player_obj->runPlayerShip(player_obj);
//     _player_thread->thread_exit(3);
//     delete _player_obj;
// }

//void Game::enemyRun

//void Game::shotRun

//void Game::inputRun


// void Game::addEnemy(sf::Sprite& enemy) {
//     _enemies.push_back(enemy);
// }

// std::vector<EnemyShip*>& Game::getEnemies() {
//     return _enemies;
// }

//gets e sets
bool Game::paused() { return _paused;}
unsigned int Game::getSpeed() {return _speed;}
unsigned int Game::getScore() {return _score;}
unsigned int Game::getEliminations() {return _eliminations;}

__END_API