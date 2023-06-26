#ifndef menu_h
#define menu_h

#include "game.h"
#include "../../thread/include/traits.h"

__BEGIN_API

class Menu : public Game
{
public:

    Menu();

    ~Menu();

    void drawMenu();

    void updateMenu();

};

__END_API

#endif
