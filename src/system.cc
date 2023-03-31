#include <stdio.h>
#include "../include/system.h"
#include "../include/traits.h"
#include "../include/debug.h"

__BEGIN_API

void System::init() {
    db<System>(TRC) << "System::init() chamado\n";
    setvbuf (stdout, 0, _IONBF, 0);
};  

__END_API