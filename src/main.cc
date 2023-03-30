#include "cpu.h"
#include <iostream>
#include "./main_class.h"
#include "./system.h"

__USING_API 


int main(void)
{
    System::init();
    Main::run();
    
    return 0;
}
