#include <iostream>

#include "../include/window.h"

//#include "../include/space.h"

__BEGIN_API

sf::RenderWindow GameWindow::window(sf::VideoMode(900,800), "VASCO da GAMA");
sf::Sprite GameWindow::maze_sprite;
sf::Texture GameWindow::maze_tex;
sf::Sprite GameWindow::player_sprite;
sf::Texture GameWindow::player_tex;

GameWindow::GameWindow() {}

GameWindow::~GameWindow() {}

void GameWindow::load_texture(std::string path, sf::Texture& texture) 
{
    bool res = texture.loadFromFile(path);
    if (!res) {
        std::cout << "Erro ao carregar a textura...";
    }
}

void GameWindow::make_sprite(
    // Sempre passar referencia, se nao o sfml faz copia
    sf::Texture& texture,
    sf::Sprite& sprite,
    double scale_x, 
    double scale_y,
    int position_x, 
    int position_y, 
    float angle
    ) 
{
    sprite.setTexture(texture);
    sprite.scale(scale_x, scale_y);
    // sprite.setPosition(position_x, position_y);
    // sprite.setRotation(angle);
}

// Inicializa sprites do objeto window
void GameWindow::init_sprites() 
{
    load_texture("sprites/maze/screen.png", get_maze_texture());
    load_texture("sprites/space_ships/space_ship1.png", get_player_texture());
    make_sprite(get_maze_texture(), get_maze_sprite(), 1.5, 1.5, 0, 0, 90);
    make_sprite(get_player_texture(), get_player_sprite(), -0.5, -0.5, 0, 0, 90);
    std::cout << "Passou make sprite\n";
}


void GameWindow::run(GameWindow *teste)
{
    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    teste->init_sprites();
    std::cout << "Chegou no run  window\n";
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
               window.close();
        }

        // Espera outros objetos desenharem
        window.draw(get_maze_sprite());
        window.display();

        Thread::yield();
    }

    bool e;
    std::cout << "close window\n";
    Game::closeWindow();
    e = Game::isWindowOpen();
    std::cout << e <<"\n";
}

__END_API