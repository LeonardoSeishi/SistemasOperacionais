#include "../include/thread.h"
#include <iostream>

__BEGIN_API

Thread * Thread::_running = nullptr;
int Thread::_counter = 0;

int Thread::id() {
    return Thread::_id;
}

Thread * Thread::running() {
    return Thread::_running;
}

int Thread::switch_context(Thread * prev, Thread * next)
{
    if (prev->id() != next->id()) {
        Thread::_running = next;
        return CPU::switch_context(prev->context(), next->context());
    } else {
        return 0;
    }
}

void Thread::thread_exit(int exit_code) {
    _exit_code = exit_code;
    _counter--;
}

CPU::Context * Thread::context()
{
    return _context;
};

Thread::~Thread()
{
    if(_context) {
        delete _context;
    }
}

__END_API