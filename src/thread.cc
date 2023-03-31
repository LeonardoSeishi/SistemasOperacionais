#include "../include/thread.h"
#include "thread.h"

__BEGIN_API

Thread * Thread::_running = nullptr;
int _counter = 0;

int Thread::switch_context(Thread * prev, Thread * next)
{
    db<Thread>(TRC) << "Thread::switch_context() chamado, id = " << prev->id() << "\n";
    if (prev->id()) {
        db<Thread>(TRC) << "Thread::switch_context() OK, id = " << prev->id() << "\n";
        Thread::set_running(next);
        return CPU::switch_context(prev->get_context(), next->get_context());
    } else {
        db<Thread>(ERR) << "Thread::switch_context() erro, id = " << prev->id() << "\n";
        return 0;
    }
}

void thread_exit(int exit_code) {
    db<Thread>(TRC) << "Thread::thread_exit() chamado, code = " << exit_code << "\n";
    _counter--;
}

Thread::~Thread()
{
    if(_context) {
        delete _context;
    }
}

__END_API