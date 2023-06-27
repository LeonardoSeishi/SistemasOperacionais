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

}

void GameWindow::sem_lock() {
    GameWindow::sem->p();
}

void GameWindow::sem_free() {
    GameWindow::sem->v();
}

void GameWindow::draw_sprite(sf::Sprite& sprite) {
    sem->p();
    sprite_queue.push_back(sprite);
    sem->v();
}

void GameWindow::run(GameWindow *window_obj)
{
    // Inicializa sprites e texturas
    window_obj->init_sprites();
    window.setKeyRepeatEnabled(true);
    // Main workload
    while (window.isOpen())
    {
        // Espera outros objetos desenharem
        sem->p();
        // Limpa artefatos
        window.clear();
        window.draw(get_maze_sprite());
        for (const auto& sprite : sprite_queue) {
            window.draw(sprite);
            sprite_queue.pop_front();
        }
        sem->v();

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