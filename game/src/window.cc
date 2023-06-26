#include <iostream>

#include "../include/window.h"

__BEGIN_API

sf::RenderWindow GameWindow::window(sf::VideoMode(1086, 746), "Jogo das Naves");
sf::Sprite GameWindow::maze_sprite;
sf::Texture GameWindow::maze_tex;
sf::Sprite GameWindow::player_sprite;
sf::Texture GameWindow::player_tex;
sf::Texture GameWindow::enemy_tex;
sf::Sprite GameWindow::enemy1_sprite;
sf::Sprite GameWindow::enemy2_sprite;
sf::Sprite GameWindow::enemy3_sprite;
sf::Sprite GameWindow::enemy4_sprite;
sf::Texture GameWindow::shot_tex;
sf::Sprite GameWindow::shot_sprite;

GameWindow::GameWindow() {}

GameWindow::~GameWindow() {}

void GameWindow::load_texture(std::string path, sf::Texture& texture) 
{
    bool res = texture.loadFromFile(path);
    if (!res) {
        std::cout << "Erro ao carregar a textura...";
    }
}

void GameWindow::make_sprite(
    // Sempre passar referencia, se nao o sfml faz copia
    sf::Texture& texture,
    sf::Sprite& sprite,
    double scale_x, 
    double scale_y,
    int position_x = 0, 
    int position_y = 0, 
    float angle = (0,0)
    ) 
{
    sprite.setTexture(texture);
    sprite.scale(scale_x, scale_y);
    sprite.setPosition(position_x, position_y);
    sprite.setRotation(angle);
}

// Inicializa sprites do objeto window
void GameWindow::init_sprites() 
{
    load_texture("sprites/maze/screen.png", get_maze_texture());
    load_texture("sprites/space_ships/space_ship1.png", get_player_texture());
    load_texture("sprites/space_ships/enemy_space_ship1.png", get_enemy_texture());

    // Calcula bounds da maze pra centralizar na window
    // N funciona ainda

    sf::Vector2u window_size = window.getSize();
    sf::FloatRect maze_bounds = get_maze_sprite().getGlobalBounds();
    float maze_w = maze_bounds.width;
    float maze_h = maze_bounds.height;
    float maze_x = (window_size.x - maze_w)/2.0f + maze_w/2.0f;
    float maze_y = (window_size.y - maze_h)/2.0f + maze_h/2.0f;


    make_sprite(get_maze_texture(), get_maze_sprite(), 2.0, 2.0);

    // PARA MOVER SPRITES:
    // Da posição 10 a 705 no sentido horizontal X
    // Da posição 10 a 685 no sentido vertical Y
    // CENTRALIZAÇÃO DO PLAYER: (390, 340)

    make_sprite(get_player_texture(), get_player_sprite(), 0.5, 0.5, 390, 340, 90);
    make_sprite(get_enemy_texture(), get_enemy1_sprite(), 0.5, 0.5, 10, 10, 0);
    make_sprite(get_enemy_texture(), get_enemy2_sprite(), 0.5, 0.5, 705, 10, 0);    
    make_sprite(get_enemy_texture(), get_enemy3_sprite(), 0.5, 0.5, 10, 685, 0);    
    make_sprite(get_enemy_texture(), get_enemy4_sprite(), 0.5, 0.5, 705, 685, 0);
   // get_enemy4_sprite().setPosition(300, 500);


    // Game::addEnemy(get_enemy1_sprite);
    // Game::addEnemy(get_enemy2_sprite);
    // Game::addEnemy(get_enemy3_sprite);
    // Game::addEnemy(get_enemy4_sprite);
}



void GameWindow::run(GameWindow *window_obj)
{
    // Inicializa sprites e texturas
    window_obj->init_sprites();
    window.setKeyRepeatEnabled(true);
    std::cout << "Chegou no run  window\n";
    // Main workload
    while (window.isOpen())
    {
        // Limpa artefatos
        window.clear();

        // Espera outros objetos desenharem

        window.draw(get_maze_sprite());
        window.draw(get_player_sprite());
        window.draw(get_enemy1_sprite());
        window.draw(get_enemy2_sprite());
        window.draw(get_enemy3_sprite());
        window.draw(get_enemy4_sprite());
        window.display();
        

        // PlayerShip& player = Game::getPlayer();
        // std::vector<EnemyShip*> enemies = Game::getEnemies();  // Assuming you have a function that returns a vector of EnemyShip pointers in Game class
        // std::vector<Projectile*> projectiles = Game::getProjectiles();  // Assuming you have a function that returns a vector of Projectile pointers in Game class
       
        // Collision::handleCollisions(player, enemies, projectiles);

        Thread::yield();
    }

    bool e;
    std::cout << "close window\n";
    Game::closeWindow();
}

__END_API