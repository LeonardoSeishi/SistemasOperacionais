#include <iostream>

#include "../include/window.h"

//#include "../include/space.h"

__BEGIN_API

sf::RenderWindow GameWindow::window(sf::VideoMode(1086, 746), "Jogo das Naves");
Semaphore *GameWindow::sem = new Semaphore();
std::deque<sf::Sprite> GameWindow::sprite_queue;
// bool can_draw = false;
sf::Sprite GameWindow::maze_sprite;
sf::Texture GameWindow::maze_tex;
sf::Sprite GameWindow::score_sprite;
sf::Texture GameWindow::score_tex;
sf::Sprite GameWindow::ready_sprite;
sf::Texture GameWindow::ready_tex;
sf::Text GameWindow::score_text;
sf::Font GameWindow::font;


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
    float angle = 0
    ) 
{
    sprite.setTexture(texture);
    sprite.scale(scale_x, scale_y);
    sprite.setPosition(position_x, position_y);
    sprite.setRotation(angle);
}

void GameWindow::write_screen(sf::Font& font, sf::Text& text, int value, int x = 880, int y = 70) {
    text.setFont(font);
    text.setCharacterSize(100);
    text.setPosition(x, y);
    text.setFillColor(sf::Color::White);
    text.setString(""+ std::to_string(value));
}


// Inicializa sprites do objeto window
void GameWindow::init_sprites() 
{
    load_texture("sprites/maze/screen.png", get_maze_texture());
    load_texture("sprites/ui/score_tex.png", get_score_texture());
    load_texture("sprites/ui/ready.png", get_ready_texture());


    // load_texture("sprites/space_ships/space_ship1.png", get_player_texture());
    // load_texture("sprites/space_ships/enemy_space_ship1.png", get_enemy_texture());

    // Calcula bounds da maze pra centralizar na window
    // N funciona ainda

    sf::Vector2u window_size = window.getSize();
    sf::FloatRect maze_bounds = get_maze_sprite().getGlobalBounds();
    float maze_w = maze_bounds.width;
    float maze_h = maze_bounds.height;
    float maze_x = (window_size.x - maze_w)/2.0f + maze_w/2.0f;
    float maze_y = (window_size.y - maze_h)/2.0f + maze_h/2.0f;


    make_sprite(get_maze_texture(), get_maze_sprite(), 2.0, 2.0);
    make_sprite(get_score_texture(), get_score_sprite(), 2.0, 2.0, 880, 30);
    make_sprite(get_ready_texture(), get_ready_sprite(), 2.0, 2.0, 880, 670);


    // PARA MOVER SPRITES:
    // Da posição 10 a 705 no sentido horizontal X
    // Da posição 10 a 685 no sentido vertical Y
    // CENTRALIZAÇÃO DO PLAYER: (390, 340)

    // make_sprite(get_player_texture(), get_player_sprite(), 0.5, 0.5, 390, 340, 90);
    // make_sprite(get_enemy_texture(), get_enemy1_sprite(), 0.5, 0.5, 10, 10, 0);
    // make_sprite(get_enemy_texture(), get_enemy2_sprite(), 0.5, 0.5, 705, 10, 0);    
    // make_sprite(get_enemy_texture(), get_enemy3_sprite(), 0.5, 0.5, 10, 685, 0);    
    // make_sprite(get_enemy_texture(), get_enemy4_sprite(), 0.5, 0.5, 705, 685, 0);

}

void GameWindow::draw_sprite(sf::Sprite& sprite) {
    // sem->p();
    sprite_queue.push_back(sprite);
    // sem->v();
}

void GameWindow::run(GameWindow *window_obj)
{

    // Inicializa sprites e texturas
    window_obj->init_sprites();
    window_obj->write_screen(font, score_text, 0);
    window.setKeyRepeatEnabled(true);

    std::cout << "Chegou no run  window\n";
    // Main workload
    while (window.isOpen())
    {
        // Espera outros objetos desenharem
        // sem->p();
        // std::cout << "AAA\n";
        // Limpa artefatos
        window.clear();
        window.draw(get_maze_sprite());
        window.draw(get_score_sprite());
        window.draw(get_ready_sprite());

        for (const auto& sprite : sprite_queue) {
            window.draw(sprite);
            sprite_queue.pop_front();
        }
        // std::cout << "BBB\n";
        // sem->v();

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