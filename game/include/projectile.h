#ifndef projectile_h
#define projectile_h

#include "game_entity.h"
#include "game.h"
#include "window.h"

__BEGIN_API

class Projectile: public GameEntity
{
public:
    Projectile(unsigned int x, unsigned int y, Direction direction);

    ~Projectile();

    bool checkPositionBound();

    static void runProjectile(Projectile * shot);

    //gets e sets
    const sf::Sprite& getSprite() const;
    void set_thread(Thread * thread);
    Thread * get_thread();

private:
    Thread * shot_thread;
    
///////////////////// game entity ////////////////////////
public:
    void move(GameEntity::Direction direction) override;

    void sem_lock() override;
    unsigned int speed() override;
    unsigned int x() override;
    unsigned int y() override;
    Direction direction() override;
    void set_direction(GameEntity::Direction direction) override;
    unsigned int get_health() override;
    void lose_health() override;

    sf::Sprite &getSprite() override;
    sf::Texture& getTexture() override;

    void set_position(unsigned int x, unsigned int y) override;

    void draw_entity(sf::Sprite &sprite, float rotation, float x, float y) override;


};

__END_API

#endif