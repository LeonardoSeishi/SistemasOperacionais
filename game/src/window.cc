#include <iostream>

#include "../include/window.h"

//#include "../include/space.h"

__BEGIN_API

sf::RenderWindow GameWindow::window(sf::VideoMode(900,800), "VASCO da GAMA");
sf::Sprite GameWindow::maze_sprite;
sf::Sprite GameWindow::shot_sprite;
sf::Sprite GameWindow::player_sprite;
sf::Sprite GameWindow::enemy_sprite;

sf::Texture GameWindow::maze_tex;
sf::Texture GameWindow::shot_tex;
sf::Texture GameWindow::player_tex;
sf::Texture GameWindow::enemy_tex;

GameWindow::GameWindow() {}

GameWindow::~GameWindow() {}

sf::Texture GameWindow::draw_texture(std::string path) 
{
    sf::Texture texture;
    texture.loadFromFile(path);
    if (!texture.loadFromFile(path)) {
        std::cout << "Erro ao carregar a textura...";
    }
    return texture;
}

sf::Sprite GameWindow::make_sprite(
    sf::Texture texture,
    double scale_x, 
    double scale_y,
    int position_x, 
    int position_y, 
    float angle
 ) {
    sf::Sprite sprite;

    sprite.setTexture(texture);
    sprite.scale(scale_x, scale_y);
    sprite.setPosition(position_x, position_y);
    sprite.setRotation(angle);

    return sprite;
}

void GameWindow::init_sprites() 
{
    maze_tex = draw_texture("sprites/maze/screen.png");
    shot_tex = draw_texture("sprites/space_ships/shot.png");
    player_tex = draw_texture("sprites/space_ships/space_ship1.png");
    enemy_tex = draw_texture("sprites/space_ships/enemy_space_ship1.png");

    maze_sprite = make_sprite(shot_tex, -2, -2, 0, 0, 90);
    window.draw(maze_sprite);

    shot_sprite = make_sprite(shot_tex, -0.5, -0.5, 204, 400, 90);
    window.draw(shot_sprite);

    player_sprite = make_sprite(player_tex, -0.5, -0.5, 204, 400, 90);
    window.draw(player_sprite);

    enemy_sprite = make_sprite(enemy_tex, -0.5, -0.5, 204, 400, 90);
    window.draw(enemy_sprite);
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

        init_sprites();
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