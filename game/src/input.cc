#include "../include/input.h"
#include "../include/spaceship.h"


__BEGIN_API

PlayerShip *Input::player;

void Input::run()
{
    sf::Event event;
    while (Game::isWindowOpen())
    {
        while (Game::getWindow().window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                std::cout << "Pausa!" << std::endl;
                // pausar o jogo
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                std::cout << "Keyboard esquerda!" << std::endl;
                player->move(Spaceship::LEFT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                std::cout << "Keyboard direita!" << std::endl;
                player->move(Spaceship::RIGHT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                std::cout << "Keyboard para baixo!" << std::endl;
                player->move(Spaceship::DOWN);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                std::cout << "Keyboard para cima!" << std::endl;
                player->move(Spaceship::UP);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                std::cout << "Close Game!" << std::endl;
                // Chamar game.endGame
                exit(1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                std::cout << "shoot!" << std::endl;
                // atirar
                // new Thread em player
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                std::cout << "reiniciar!" << std::endl;
                // reiniciar
                // game_control->restart();
            }
        }
        
        Thread::yield();
    }
    // else
    // {
    //     std::cout << "Keyboard pressed = " << event.key.code << std::endl;
    //     break;
    // }
}

__END_API
