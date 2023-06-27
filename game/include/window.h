#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <deque>

#include "../../thread/include/traits.h"
#include "../../thread/include/thread.h"
#include "../../thread/include/semaphore.h"

#include "game.h"
#include "window.h"


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

    static void draw_sprite(sf::Sprite& sprite);

    static void run(GameWindow *window_obj);

    // Getters
    static sf::Sprite& get_maze_sprite() { return maze_sprite; }
    static sf::Texture& get_maze_texture() { return maze_tex; }

    // static sf::Sprite& get_player_sprite() { return player_sprite; }
    // static sf::Texture& get_player_texture() { return player_tex; }

    // static sf::Texture &get_enemy_texture() { return enemy_tex; }

    // static sf::Sprite &get_enemy1_sprite() { return enemy1_sprite; }
    // static sf::Sprite &get_enemy2_sprite() { return enemy2_sprite; }
    // static sf::Sprite &get_enemy3_sprite() { return enemy3_sprite; }    
    // static sf::Sprite &get_enemy4_sprite() { return enemy4_sprite; }

    // static sf::Sprite& get_shot_sprite() { return shot_sprite; }
    // static sf::Texture& get_shot_texture() { return shot_tex; }

public:
    static sf::RenderWindow window;
    static Semaphore *sem;
    static std::deque<sf::Sprite> sprite_queue;

private:

    Thread _render_thread;
    static sf::Texture maze_tex;
    static sf::Sprite maze_sprite;
    static bool can_draw;
    
    // static sf::Texture player_tex;
    // static sf::Sprite player_sprite;

    // static sf::Texture enemy_tex;
    // static sf::Sprite enemy1_sprite;
    // static sf::Sprite enemy2_sprite;
    // static sf::Sprite enemy3_sprite;
    // static sf::Sprite enemy4_sprite;

    // static sf::Texture shot_tex;
    // static sf::Sprite shot_sprite;

    
};

__END_API

#endif