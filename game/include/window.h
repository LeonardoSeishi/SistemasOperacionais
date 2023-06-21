#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "thread.h"
#include "spaceship.h"
#include "semaphore.h"

__BEGIN_API
class GameWindow
{
public:
    GameWindow();

    ~GameWindow();

    static void run(sf::RenderWindow* window, sf::Sprite* sprite);

    static void draw_texture(sf::RenderWindow* window, sf::Sprite* sprite, int x, int y, float angle);

    static void init();

    static Semaphore sem;

private:
    void load_and_bind_textures();


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*acredito que a gente tera que remodelar essa classe inteira
do que jeito que esta aqui, todos os inimigos terao a mesma imagem
tirando a independencia deles
*/
private:
    //static Thread * spaceships[5];
    sf::RenderWindow game_window;
    Thread* _render_thread;
    // Maze Texture
    sf::Texture maze_tex;
    sf::Sprite maze_sprite;
    
    //Shot texture
    sf::Texture shot_tex;
    sf::Sprite shot_sprite;
};

__END_API

#endif