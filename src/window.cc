#include "../include/window.h"

//#include "../include/space.h"

__BEGIN_API

GameWindow::GameWindow()
{
    load_and_bind_textures();
}

void GameWindow::draw_texture(sf::Sprite* sprite, int length, int height, float angle)
{
}

void GameWindow::run()
{
    sf::RenderWindow window(sf::VideoMode(900, 560), "SFML works!");

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {

        window.clear();
        window.draw(maze_sprite);

        window.display();
    }
}

void GameWindow::load_and_bind_textures()
{
    // Bind map textures    
    maze_tex.loadFromFile("sprites/maze/screen.png");
    maze_sprite.setTexture(maze_tex);
    maze_sprite.scale(1.5, 1.5);

    shot_tex.loadFromFile("sprites/space_ships/shot.png");
    shot_sprite.setTexture(shot_tex);
    shot_sprite.scale(-0.5, -0.5);
}


//void enemy_movement(){}

//static void enemy_movement(){}
__END_API