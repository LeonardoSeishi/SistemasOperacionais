#include "../include/input.h"


__BEGIN_API

PlayerShip *Input::player;

void Input::run()
{
    sf::Event event;
    while (Game::isWindowOpen())
    {
        while (Game::getWindow().window.pollEvent(event)) {
            // GameWindow::sem_lock();
            if (event.type == sf::Event::Closed) {
                Game::getWindow().window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                std::cout << "Pausa!" << std::endl;
                // pausar o jogo
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                std::cout << "Keyboard esquerda!" << std::endl;
                player->move(GameEntity::LEFT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                std::cout << "Keyboard direita!" << std::endl;
                player->move(GameEntity::RIGHT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                std::cout << "Keyboard para baixo!" << std::endl;
                player->move(GameEntity::DOWN);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                std::cout << "Keyboard para cima!" << std::endl;
                player->move(GameEntity::UP);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                std::cout << "Close Game!" << std::endl;
                exit(1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                std::cout << "shoot!" << std::endl;
                player->shoot();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                std::cout << "reiniciar!" << std::endl;
                // reiniciar
            }
        }
        
        Thread::yield();
    }
}

__END_API
