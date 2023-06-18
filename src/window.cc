#include "../include/window.h"
#include "../include/semaphore.h"
#include "../include/thread.h"
#include "../include/spaceship.h"
#include "../include/game.h"
//#include "../include/space.h"


Window::Window()
{
    load_and_bind_textures();
}

void Window::draw_texture(unsigned int texture, int length, int height, float angle)
{
}

void Window::run()
{
    sf::RenderWindow window(sf::VideoMode(900, 560), "SFML works!");

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    window.setKeyRepeatEnabled(false);

    PlayerShip * player = new PlayerShip(220, 365);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                 window.close();
                 break;
            
            // key pressed
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "Keyboard esquerda!" << std::endl;
                    player->move_left();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                    player->move_right();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                    player->move_down();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                    player->move_up();
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    std::cout << "Pausa!" << std::endl;
                    //pausar o jogo 
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    std::cout << "Close Game!" << std::endl;
                    //sair do jogo 
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    std::cout << "shoot!" << std::endl;
                    //
                } else {
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                break;
                }
            
            }
        }

        window.clear();
        window.draw(maze_sprite);
        

        //area de testes
        if (player->direction() == Spaceship::UP) {
            space_ship_sprite_up.setPosition(player->x(), player->y());
            window.draw(space_ship_sprite_up);
        } else if (player->direction() == Spaceship::DOWN) {
            space_ship_sprite_down.setPosition(player->x(), player->y());
            window.draw(space_ship_sprite_down);
        } else if (player->direction() == Spaceship::LEFT) {
            space_ship_sprite_left.setPosition(player->x(), player->y());
            window.draw(space_ship_sprite_left);
        } else if (player->direction() == Spaceship::RIGHT) {
            space_ship_sprite_right.setPosition(player->x(), player->y());
            window.draw(space_ship_sprite_right);
        }



        enemy_ship_sprite.setPosition(245, 150);
        window.draw(enemy_ship_sprite);

        shot_sprite.setPosition(204, 400);
        window.draw(shot_sprite);
        
        window.display();
    }
}

void Window::load_and_bind_textures()
{
    // Bind map textures    
    maze_tex.loadFromFile("sprites/maze/screen.png");
    maze_sprite.setTexture(maze_tex);
    maze_sprite.scale(1.5, 1.5);

    shot_tex.loadFromFile("sprites/space_ships/shot.png");
    shot_sprite.setTexture(shot_tex);
    shot_sprite.scale(-0.5, -0.5);



    space_ship_tex_up.loadFromFile("sprites/space_ships/space_ship3.png");
    space_ship_sprite_up.setTexture(space_ship_tex_up);
    space_ship_sprite_up.scale(-0.5, -0.5);

    space_ship_tex_left.loadFromFile("sprites/space_ships/space_ship4.png");
    space_ship_sprite_left.setTexture(space_ship_tex_left);
    space_ship_sprite_left.scale(-0.5, -0.5);

    space_ship_tex_down.loadFromFile("sprites/space_ships/space_ship1.png");
    space_ship_sprite_down.setTexture(space_ship_tex_down);
    space_ship_sprite_down.scale(-0.5, -0.5);

    space_ship_tex_right.loadFromFile("sprites/space_ships/space_ship2.png");
    space_ship_sprite_right.setTexture(space_ship_tex_right);
    space_ship_sprite_right.scale(-0.5, -0.5);



    enemy_ship_tex.loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    enemy_ship_sprite.setTexture(enemy_ship_tex);
    enemy_ship_sprite.scale(-0.5, -0.5);
}
