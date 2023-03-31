#include "../include/thread.h"
#include "thread.h"

__BEGIN_API

Thread * Thread::_running = nullptr;
int _counter = 0;

int Thread::switch_context(Thread * prev, Thread * next)
{
    if (prev->id()) {
        db<Thread>(TRC) << "Thread::switch_context() chamado, id = " << prev->id() << "\n";
        Thread::set_running(next);
        return CPU::switch_context(prev->get_context(), next->get_context());
    } else {
        db<Thread>(TRC) << "Thread::switch_context() erro\n";
        return 0;
    }
}

void thread_exit(int exit_code) {
    _counter--;
}

Thread::~Thread()
{
    if(_context) {
        delete _context;
    }
}

__END_API