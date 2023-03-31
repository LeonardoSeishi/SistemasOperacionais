#include "../include/thread.h"

__BEGIN_API

Thread * Thread::_running = nullptr;
int _counter = 0;

static int switch_context(Thread *prev, Thread *next)
{
    if (prev->id()) {
        Thread::set_running(next);
        return CPU::switch_context(prev->get_context(), next->get_context());
    } else {
        return 0;
    }
}

void thread_exit(int exit_code) {
    _counter--;
}

Thread::~Thread() {
    if(_context) {
        delete _context;
    }
}

__END_API