#include "../include/menu.h"

__BEGIN_API

sf::Texture _hi_score_tex;
sf::Sprite _hi_score_sprite;

sf::Texture _score_tex;
sf::Sprite _score_sprite;

sf::Texture _level_tex;
sf::Sprite _level_sprite;

sf::Texture _speed_tex;
sf::Sprite _speed_sprite;

sf::Font _hi_score;
sf::Font _score;
sf::Font _level;
sf::Font _speed;

Menu::Menu() {}

Menu::~Menu() {}

// PARA MOVER SPRITES MENU:
// Da posição 715 a 1076 no sentido horizontal X
// Da posição 10 a 685 no sentido vertical Y
// CENTRALIZAÇÃO DO MENU: (880, 340)

void Menu::draw_menu()
{
    load_texture("sprites/ui/score.png", _score_tex);
    //make_sprite(_score_tex, _score_sprite, 2.0, 2.0);

    // texts.resize(5);
    // sizes = {20, 28, 24, 24, 24};

    // for (std::size_t i{}; i < texts.size(); ++i)
    // {
    //     texts[i].setFont(*font);
    //     texts[i].setString(options[i]);
    //     texts[i].setCharacterSize(sizes[i]);
    //     texts[i].setOutlineColor(sf::Color::Black);
    //     texts[i].setPosition(coords[i]);
    // }
    // texts[1].setOutlineThickness(4);

}

void Menu::reset_menu() {

}

// void Menu::runMenu()
// {
//     draw_menu();
//     while (GameWindow::window.isOpen())
//     {
//         update_menu();
//         Thread::yield();
//     }
// }

void Menu::run(Menu *menu) {
    std::cout << "Chegou no run meu\n";

    while (Game::isWindowOpen()) {
        // std::cout << "Game::isWindowOpen()\n";
        //Game::sem()->p();
        Thread::yield();
        //Game::sem()->v();
    }
}

__END_API
