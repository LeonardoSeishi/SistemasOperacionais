#include <cstdlib>
#include "../include/game.h"


__BEGIN_API

// ENEMY
EnemyShip::EnemyShip(unsigned int x, unsigned int y, unsigned int speed, bool algoth)
{
    _x = x;
    _y = y;
    _speed = speed;
    _health = 1;
    _algth = algoth;
    _sem = new Semaphore(1);

    // Inicializa sprite
    getTexture().loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    getSprite().setTexture(getTexture());
    getSprite().setPosition(x, y);
    getSprite().scale(0.5, 0.5);
}

EnemyShip::~EnemyShip() {
    delete _sem;
}

void EnemyShip::lose_life()
{
    // morrer
    // suspender a thread por 2 segundos
}

std::pair<int, int> EnemyShip::get_random_pair() {
    const int min = 1;
    const int max = 4;
    const double fraction = 1.0 / (RAND_MAX + 1.0);

    std::srand(static_cast<unsigned int>(std::time(0)));

    int random_x = min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
    int random_y = min + static_cast<int>((max - min + 1) * (std::rand() * fraction));

    int new_x = x(), new_y = y();
    switch (random_x)
    {
    case 1:
        // UP
        if (y() > 10) {
            new_y = y() + 1;
            move(UP);
            draw_entity(getSprite(), 90, x(), y());
            GameWindow::draw_sprite(getSprite());
        } else {
            new_y = y() - 1;
            move(DOWN);
            draw_entity(getSprite(), 90, x(), y());
            GameWindow::draw_sprite(getSprite());
        }
        break;
    case 2:
        // Down
        if (y() < 685) {
            new_y = y() - 1;
            move(DOWN);
            draw_entity(getSprite(), 90, x(), y());
            GameWindow::draw_sprite(getSprite());
        } else {
            new_y = y() + 1;
            
        }
        break;
    case 3:
        // Left
        if (x() > 10) {
            new_x = x() - 1;
            move(LEFT);

        } else {
            new_x = x() + 1;
            move(RIGHT);
        }
        break;
    case 4:
        // if (x() < )
        new_x = x() + 1;
        break;
    default:
        break;
    }

    std::pair<int, int> nome(random_x, random_y);
    return nome;

}
std::pair<int, int> EnemyShip::get_circ_pair() {
    if (x() <= 10)
    {
        move(RIGHT);
        draw_entity(getSprite(), 90, x(), y());
        GameWindow::draw_sprite(getSprite());
    }
    if (x() > 10 && y() < 705)
    {
        move(LEFT);
        draw_entity(getSprite(), 90, x(), y());
        GameWindow::draw_sprite(getSprite());
    }
    if (y() < 685 && y() > 10)
    {
        move(DOWN);
        draw_entity(getSprite(), 90, x(), y());
        GameWindow::draw_sprite(getSprite());
    }
    if (y() >= 685) 
    {
        move(UP);
        draw_entity(getSprite(), 90, x(), y());
        GameWindow::draw_sprite(getSprite());
    }
    if (y() == 10)
    {
        move(DOWN);
        draw_entity(getSprite(), 90, x(), y());
    }

    std::pair<int, int> nome(x(),y());
    return nome;
}

void EnemyShip::runEnemyShip(EnemyShip *enemy, int algoritmo)
{
    std::cout << "Chegou no run enemyship\n";

    while (Game::isWindowOpen())
    {
        // calcular a direction dependendo de qual parede ele ira surgir
        // 705 = parede_direita
        // 685 = valor_chao
        // Angulos
        /* 90 - 
        */
        if (enemy->_algth) {
            std::pair<int, int> coord = enemy->get_random_pair();
            enemy->set_position(coord.first, coord.second);

        } else {
            std::pair<int, int> coord = enemy->get_circ_pair();
            enemy->set_position(coord.first, coord.second);
        }
        GameWindow::draw_sprite(enemy->getSprite());
        Thread::yield();

    }
}

__END_API