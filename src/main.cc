#include <iostream>
#include "../include/system.h"
#include "../include/main_class.h"
#include "../include/system.h"

__USING_API 


int main(void)
{
    System::init();
    Main *m = new Main();
    delete m;
}
