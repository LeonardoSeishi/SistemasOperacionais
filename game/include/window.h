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

    void write_screen(sf::Font& font, sf::Text& text, int value, int x, int sy);

    static void run(GameWindow *window_obj);

    // Getters
    static sf::Sprite& get_maze_sprite() { return maze_sprite; }
    static sf::Texture& get_maze_texture() { return maze_tex; }

    static sf::Sprite& get_score_sprite() { return score_sprite; }
    static sf::Texture& get_score_texture() { return score_tex; }

    static sf::Sprite& get_ready_sprite() { return ready_sprite; }
    static sf::Texture& get_ready_texture() { return ready_tex; }

public:
    static sf::RenderWindow window;
    static Semaphore *sem;
    static std::deque<sf::Sprite> sprite_queue;

private:
    Thread _render_thread;
    static sf::Texture maze_tex;
    static sf::Sprite maze_sprite;
    static sf::Texture score_tex;
    static sf::Sprite score_sprite;
    static sf::Texture ready_tex;
    static sf::Sprite ready_sprite;
    static sf::Font font;
    static sf::Text score_text;

    static bool can_draw;    

};

__END_API

#endif