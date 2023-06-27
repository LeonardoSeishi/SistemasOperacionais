#include "../include/spaceship.h"
//PLAYER

__BEGIN_API

PlayerShip::PlayerShip(int x, int y) {
    _health = 3;
    _direction = UP;
    _speed = 10;
    _x = x;
    _y = y;
    _sem = new Semaphore(1);
    // Inicializa sprite da nave
    getTexture().loadFromFile("sprites/space_ships/space_ship1.png");
    getSprite().setTexture(getTexture());
    getSprite().setPosition(x, y);
    getSprite().scale(0.5, 0.5);
}

PlayerShip::~PlayerShip() {
    delete _sem;
}

void PlayerShip::runPlayerShip(PlayerShip *player)
{
    std::cout << "Chegou no run playership\n";
    while (Game::isWindowOpen())
    {
        // Game::sem()->p();
        GameWindow::draw_sprite(player->getSprite());
        Thread::yield();
        // Game::sem()->v();
    }
}

//retorna True se a nave morrer
bool PlayerShip::lose_life() {
    if (_health > 1) {
        _health--;
        return 0;
    } else {
        //matar a nave
        return 1;
    }
}

unsigned int PlayerShip::health() {
    return _health;
}

__END_API