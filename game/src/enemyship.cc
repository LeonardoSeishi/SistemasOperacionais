#include "../include/game.h"

__BEGIN_API

// ENEMY
EnemyShip::EnemyShip(unsigned int x, unsigned int y, unsigned int speed)
{
    _x = x;
    _y = y;
    _speed = speed;
    _health = 1;
    _sem = new Semaphore(1);

    getTexture().loadFromFile("sprites/space_ships/space_ship1.png");
    getSprite().setTexture(getTexture());
    getSprite().setPosition(x, y);
    getSprite().scale(0.5, 0.5);

    // calcular a direction dependendo de qual parede ele ira surgir
    // 705 = parede_direita
    // 685 = valor_chao
    // else if (_y > 685 && _x > 0 && _x < 705) {
    //     _direction = UP;
    // }
    // else if (_y > 685 && _x > 0 && _x < 705) {
    //     _direction = UP;
    // }
}

EnemyShip::~EnemyShip() {
    delete _sem;
}

void EnemyShip::lose_life()
{
    // morrer
    // suspender a thread por 2 segundos
}

void EnemyShip::runEnemyShip(EnemyShip *enemy, int algoritmo)
{
    std::cout << "Chegou no run enemyship\n";

    while (Game::isWindowOpen())
    {
        if (enemy->x() < 0 && enemy->x() > 0 && enemy->x() < 705)
        {
            enemy->move(DOWN);
            GameWindow::draw_sprite(enemy->getSprite());
        }
        else if (enemy->y() > 685 && enemy->x() > 0 && enemy->x() < 705)
        {
            enemy->move(UP);
            GameWindow::draw_sprite(enemy->getSprite());
        }
        Thread::yield();

    }
}

__END_API