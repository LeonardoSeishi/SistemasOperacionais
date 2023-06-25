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

    void load_texture(std::string path, sf::Texture& texture);

    void make_sprite(
        sf::Texture& texture,
        sf::Sprite& sprite,
        double scale_x, 
        double scale_y,
        int position_x, 
        int position_y, 
        float angle
    );

    void init_sprites();

    static void init();

    static void run(GameWindow *teste);

    static void draw_entity();

    // Getters
    static sf::Sprite& get_maze_sprite() { return maze_sprite; }
    static sf::Texture& get_maze_texture() { return maze_tex; }

    static sf::Sprite& get_player_sprite() { return player_sprite; }
    static sf:: Texture& get_player_texture() { return player_tex; }

public:
    static sf::RenderWindow window;
    static Semaphore sem;

private:

    Thread _render_thread;
    static sf::Texture maze_tex;
    static sf::Sprite maze_sprite;
    
    static sf::Texture player_tex;
    static sf::Sprite player_sprite;

    sf::Texture enemy_tex;
    sf::Sprite enemy_sprite;
    
    sf::Texture shot_tex;
    sf::Sprite shot_sprite;

    
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