#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "spaceship.h"
#include "../../thread/include/traits.h"
#include "../../thread/include/thread.h"
#include "../../thread/include/semaphore.h"

__BEGIN_API
class GameWindow
{
public:
    GameWindow();

    ~GameWindow();

    static void run();

    static sf::Texture draw_texture(std::string path);

    static sf::Sprite make_sprite(
        sf::Texture texture,
        double scale_x, 
        double scale_y,
        int position_x, 
        int position_y, 
        float angle
    );

    static void init();

    static void init_sprites();

    static sf::RenderWindow window;
    static Semaphore sem;

    static sf::Texture maze_tex;
    static sf::Sprite maze_sprite;
    
    static sf::Texture player_tex;
    static sf::Sprite player_sprite;

    static sf::Texture enemy_tex;
    static sf::Sprite enemy_sprite;
    
    static sf::Texture shot_tex;
    static sf::Sprite shot_sprite;

protected:


private:
    //static Thread * spaceships[5];

    // sf::RenderWindow game_window;
    Thread _render_thread;

    
};

/*
inline GameWindow::GameWindow(){ //: game_window(sf::VideoMode(900, 560, 32), "Game"){//, sf::Style::Titlebar | sf::Style::Close) {
    // game_window.setKeyRepeatEnabled(false);
    window.create(sf::VideoMode(900, 800, 32), "Game");
    window.setKeyRepeatEnabled(false);
    // load_and_bind_textures();
    maze_tex.loadFromFile("sprites/maze/screen.png");
    maze_sprite.setTexture(maze_tex);
    maze_sprite.scale(1.5, 1.5);
    // while(game_window.isOpen()) {
    //     game_window.clear();
    //     sf::Event event;
    //     while (game_window.pollEvent(event))
    //     {
    //         // "close requested" event: we close the window
    //         if (event.type == sf::Event::Closed)
    //             game_window.close();
    //     }
    //     game_window.draw(maze_sprite);
    // }
    // new (&_render_thread) Thread(GameWindow::run, &game_window, &maze_sprite);
}
*/
__END_API

#endif