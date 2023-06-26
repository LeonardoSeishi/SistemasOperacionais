#ifndef menu_h
#define menu_h

#include "window.h"
#include <vector>

__BEGIN_API

class Menu : public GameWindow
{
public:
    Menu();

    ~Menu();

    void draw_menu();

    void init_fonts(sf::Font * font);

    void init_menu();

    static void run(Menu *menu);

    void update_menu();

    void reset_menu();

    static sf::Font &get_hi_score_font() { return _hi_score; }
    static sf::Font &get_score_font() { return _score; }
    static sf::Font &get_level_font() { return _level; }
    static sf::Font &get_speed_font() { return _speed; }

    std::vector<const char *> options;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

    unsigned int MENU_MIN_WIDTH;
    unsigned int MENU_MAX_WIDTH;
    unsigned int MENU_MIN_HEIGHT;
    unsigned int MENU_MAX_HEIGHT;

private:
    static sf::Texture _hi_score_tex;
    static sf::Sprite _hi_score_sprite;

    static sf::Texture _score_tex;
    static sf::Sprite _score_sprite;

    static sf::Texture _level_tex;
    static sf::Sprite _level_sprite;

    static sf::Texture _speed_tex;
    static sf::Sprite _speed_sprite;

    static sf::Font _hi_score;
    static sf::Font _score;
    static sf::Font _level;
    static sf::Font _speed;
};

__END_API

#endif
