#include "../include/window.h"

//#include "../include/space.h"

__BEGIN_API

GameWindow::GameWindow()
{
    game_window = new sf::RenderWindow(sf::VideoMode(900, 560), "SFML works!");
    game_window->setKeyRepeatEnabled(false);
    load_and_bind_textures();
    
    _render_thread = new Thread(run, game_window, &maze_sprite);
}

GameWindow::~GameWindow() {
    // humm?
    delete game_window;
}

void GameWindow::init() {
    // new (&sem) Semaphore(1);
    // new (&_render_thread) Thread(run);
}

void GameWindow::draw_texture(sf::RenderWindow* window, sf::Sprite* sprite, int x, int y, float angle)
{
    sprite->setPosition(x, y);
    sprite->setRotation(angle);
    window->draw(*sprite);
}

void GameWindow::run(sf::RenderWindow* window, sf::Sprite* sprite)
{

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    while (window->isOpen())
    {

        // game_window->clear();
        window->draw(*sprite);
        // Espera threads das naves e tiros
        std::cout << "run da window\n";
        window->display();
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