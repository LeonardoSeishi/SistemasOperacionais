#include "../include/game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::kill(/**/) { //passar nave inimiga como parameto para destruila???
    //delete EnemyShip
    _score = score() + 100;

    if (speed() < 3) {              //checar se nao esta na velocidade maxima
        if(eliminations() < 4) {
            _speed = speed() + 1;   //aumenta a velocidade do jogo
            _eliminations = 0;      //reseta a contagem
        } else {
            _eliminations = eliminations() + 1;
        }
    }
}

void Game::restart() {
    _score = 0;
    _speed = 1;
    _eliminations = 0;

}

//gets e sets
unsigned int Game::speed() {return _speed;}
unsigned int Game::score() {return _score;}
unsigned int Game::eliminations() {return _eliminations;}