#include "../include/thread.h"
#include "thread.h"

__BEGIN_API

Thread * Thread::_running = nullptr;
int _counter = 0;


int Thread::id() {
    return Thread::_id;
}


CPU::Context * Thread::get_context()
{
    return Thread::_context;
};


Thread * Thread::running() {
    return Thread::_running;
}


int Thread::switch_context(Thread * prev, Thread * next)
{
    if (prev->id() != next->id()) {
        Thread::_running = next;
        return CPU::switch_context(prev->get_context(), next->get_context());
    } else {
        return 0;
    }
}

void Thread::thread_exit(int exit_code) {
    _counter--;
}

Thread::~Thread()
{
    if(_context) {
        delete _context;
    }
}

__END_API