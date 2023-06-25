#include "../include/spaceship.h"

__BEGIN_API


void Spaceship::move(Spaceship::Direction direction) {
    unsigned int new_x = x();
    unsigned int new_y = y();
    // Speed pode ser o numero de vezes que inimigos se movimentam antes de player
    switch (direction) {
        case UP:
            new_y -= speed();
            _direction = UP;
            GameWindow::draw_entity(GameWindow::get_player_sprite(), 0, new_x, new_y);
            break;
        case DOWN:
            new_y += speed();
            _direction = DOWN;
            GameWindow::draw_entity(GameWindow::get_player_sprite(), 180, new_x, new_y);
            break;
        case LEFT:
            new_x -= speed();
            _direction = LEFT;
            GameWindow::draw_entity(GameWindow::get_player_sprite(), 270, new_x, new_y);
            break;
        case RIGHT:
            new_x += speed();
            _direction = RIGHT;
            GameWindow::draw_entity(GameWindow::get_player_sprite(), 90, new_x, new_y);
            break;
    }
    set_position(new_x, new_y);
}

void Spaceship::shoot() {
    unsigned int projectile_x = x();
    unsigned int projectile_y = y();
    Direction projectile_direction = direction();
}

__END_API