#ifndef enemy_handler_h
#define enemy_handler_h

#include "spaceship.h"
#include "../../thread/include/thread.h"

__BEGIN_API

//estou pesando em fazer dessa classe responsavel por criar todos os inimigos
//e controlar o spawn dos inimigos e por aleatorizar entre os algoritmos de movimentacao

class EnemyHandler 
{
 public:
    void runEnemyHandler();
    void spawnEnemy();
    void destroyEnemy();
    void setSpeed();

 private:
    Thread * _enemylist[4]; 
};

__END_API

#endif