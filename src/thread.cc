#include "../include/thread.h"

__BEGIN_API

Thread * Thread::_running = nullptr;

static int switch_context(Thread *prev, Thread *next)
{
    return CPU::switch_context(prev->get_context(), next->get_context());
}

__END_API