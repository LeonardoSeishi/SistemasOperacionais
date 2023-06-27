#include "../include/spaceship.h"
//PLAYER

__BEGIN_API

PlayerShip::PlayerShip(int x, int y) {
    _health = 3;
    _direction = UP;
    _speed = 10;
    //* meio da tela
    _x = x;
    _y = y;
    _sem = new Semaphore(1);
    // Inicializa sprite da nave
    sf::Texture tex;
    tex.loadFromFile("sprites/space_ships/space_ship1.png");
    _entity_sprite.setTexture(tex);
    _entity_sprite.setPosition(x, y);
}

PlayerShip::~PlayerShip() {
    delete _sem;
}

void PlayerShip::runPlayerShip(PlayerShip *player)
{
    std::cout << "Chegou no run playership\n";
    while (Game::isWindowOpen())
    {
        // std::cout << "Game::isWindowOpen()\n";
        // Game::sem()->p();
        GameWindow::draw_sprite(player->getSprite());
        Thread::yield();
        // Game::sem()->v();
    }
}

//retorna True se a nave morrer
bool PlayerShip::lose_life() {
    /*ideias:
    -piscar o sprite
    -ficar invulneravel durante 1 segundo*/
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


//------------------------------------------------------------
// METODOS DA INTERFACE


__END_API