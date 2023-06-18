#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "thread.h"
#include "spaceship.h"
#include "semaphore.h"

class Window
{
public:
    Window();

    void run();

    void draw_texture(unsigned int texture, int length, int height, float angle);

private:
    void load_and_bind_textures();


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*acredito que a gente tera que remodelar essa classe inteira
do que jeito que esta aqui, todos os inimigos terao a mesma imagem
tirando a independencia deles
*/
private:
    //static Thread * spaceships[5];
    //static Semaphore * sem;

    // Maze Texture
    sf::Texture maze_tex;
    sf::Sprite maze_sprite;
    
    //Shot texture
    sf::Texture shot_tex;
    sf::Sprite shot_sprite;
    
    //Space ship texture
    sf::Texture space_ship_tex_up;
    sf::Sprite space_ship_sprite_up;
    sf::Texture space_ship_tex_left;
    sf::Sprite space_ship_sprite_left;
    sf::Texture space_ship_tex_down;
    sf::Sprite space_ship_sprite_down;
    sf::Texture space_ship_tex_right;
    sf::Sprite space_ship_sprite_right;


    //Enemy space ship texture
    sf::Texture enemy_ship_tex;
    sf::Sprite enemy_ship_sprite;
};

#endif