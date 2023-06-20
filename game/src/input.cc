#include "../include/input.h"

__BEGIN_API

void Input::prun()
{
    sf::Event event;
    while (game_running_status)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            std::cout << "Pausa!" << std::endl;
            // pausar o jogo
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            std::cout << "Keyboard esquerda!" << std::endl;
            player->move_left();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            std::cout << "Keyboard direita!" << std::endl;
            player->move_right();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            std::cout << "Keyboard para baixo!" << std::endl;
            player->move_down();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            std::cout << "Keyboard para cima!" << std::endl;
            player->move_up();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            std::cout << "Close Game!" << std::endl;
            // Chamar game.endGame
            exit(1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            std::cout << "shoot!" << std::endl;
            // atirar
            // new Thread em player
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            std::cout << "reiniciar!" << std::endl;
            // reiniciar
            // game_control->restart();
        }
    }
    // else
    // {
    //     std::cout << "Keyboard pressed = " << event.key.code << std::endl;
    //     break;
    // }
}

__END_API
