#include <stdio.h>
#include "../include/traits.h"

__BEGIN_API

class System {

    public:
        static void init() {
            setvbuf (stdout, 0, _IONBF, 0);
        };
        
};

__END_API