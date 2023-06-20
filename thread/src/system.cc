#include <stdio.h>
#include "../include/system.h"
#include "../include/traits.h"
#include "../include/debug.h"
#include "../include/thread.h"

__BEGIN_API

void System::init(void (*main)(void*)) {
    db<System>(TRC) << "System::init() chamado\n";
    setvbuf (stdout, 0, _IONBF, 0);
    // Inicializa thread main
    Thread::init(main);
};  

__END_API