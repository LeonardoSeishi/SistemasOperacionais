#include "../include/thread.h"

__BEGIN_API

static int switch_context(Thread *prev, Thread *next)
{
    return CPU::switch_context(prev->get_self_context(), next->get_self_context());
}

__END_API