#include <iostream>

#include "../include/window.h"

//#include "../include/space.h"

__BEGIN_API

sf::RenderWindow GameWindow::window(sf::VideoMode(900,800), "VASCO da GAMA");
sf::Sprite GameWindow::maze_sprite;

GameWindow::GameWindow() {}
GameWindow::~GameWindow() {
    // humm?
    // delete _render_thread;
}

void GameWindow::init() {
    sf::Texture teste;
    teste.loadFromFile("sprites/maze/screen.png");
    maze_sprite.setTexture(teste);
    maze_sprite.scale(1.5, 1.5);
    // new (&sem) Semaphore(1);
}

void GameWindow::draw_texture(sf::RenderWindow window, sf::Sprite sprite, int x, int y, float angle)
{
    sprite.setPosition(x, y);
    sprite.setRotation(angle);
    window.draw(sprite);
}

void GameWindow::run()
{

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
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
        window.draw(maze_sprite);
        window.display();
    }
}


// void GameWindow::load_and_bind_textures()
// {
//     // Bind map textures    
//     maze_tex.loadFromFile("sprites/maze/screen.png");
//     maze_sprite.setTexture(maze_tex);
//     maze_sprite.scale(1.5, 1.5);

//     // shot_tex.loadFromFile("sprites/space_ships/shot.png");
//     if (!shot_tex.loadFromFile("sprites/space_ships/shot.png")) {
//         std::cout << "Erro carregando textura tiro\n";
//     }
//     shot_sprite.setTexture(shot_tex);
//     shot_sprite.scale(-0.5, -0.5);
// }

__END_API