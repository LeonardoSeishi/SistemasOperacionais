#include "../include/thread.h"
#include "../include/cpu.h"
#include <iostream>
#include <chrono>

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
    // Modifica estado
    _state = FINISHING;
    // Sinaliza escalonador
    yield();
}

CPU::Context * Thread::context()
{
    return _context;
};

Thread::~Thread()
{
    // Remove thread da fila de prontos
    Thread::_ready.remove(this);
    if(_context) {
        delete _context;
    }
}

// Trabalho 3

Thread Thread::_main;
CPU::Context Thread::_main_context;
Thread Thread::_dispatcher;
Thread::Ready_Queue Thread::_ready;

void Thread::init(void (*main)(void*)) {
    // Inicializar fila de threads prontas
    new (&_ready) Thread::Ready_Queue();
    // Inicializar thread Main passando como parametro o ponteiro da funcao main
    new (&_main) Thread(main, (void*) "Main");
    new (&_main_context) CPU::Context();
    // Inicializar thread Dispatcher
    new (&_dispatcher) Thread((void (*)(void *)) & Thread::dispatcher, (void *)NULL);
    // Atualiza estado da main
    Thread::_main._state = RUNNING;
    Thread::_running = &Thread::_main;
    // Trocar contexto para thread main
    CPU::switch_context(&_main_context, _main.context());
}

/*
 * Daspachante (disptacher) de threads.
 * Executa enquanto houverem threads do usuário.
 * Chama o escalonador para definir a próxima tarefa a ser executada.
 */
void Thread::dispatcher() {
    db<Thread>(TRC) << "Dispatcher executando.\n";
    // Enquanto existir thread do usuario
    while (Thread::_counter > 2) {
        // Escolhe proxima thread a ser executada
        Thread *first = Thread::_ready.remove()->object();
        // Atualiza status da propia thread dispatcher pra READY e reinsere a mesma em _ready
        Thread::_dispatcher._state = READY;
        Thread::_ready.insert(&Thread::_dispatcher._link);
        // Atualiza o ponteiro _running para apontar para a proxima thread a ser executada
        Thread::_running = first;
        // Atualiza o estado da proxima thread a ser executada
        first->_state = RUNNING;
        // Troca o contexto entre as duas threads
        Thread::switch_context(&Thread::_dispatcher, first);
        // Testa se o estado da proxima thread eh FINISHING e caso afirmativo remove de _ready
        if (first->_state == FINISHING) {
            Thread::_ready.remove(first);
        }
    }
    // Muda o estado da thread dispatcher para FINISHING
    Thread::_dispatcher._state = FINISHING;
    // Remove a thread dispatcher da fila de prontos
    Thread::_ready.remove(&Thread::_dispatcher);
    // Troca o contexto de dispatcher para main
    Thread::switch_context(&Thread::_dispatcher, &Thread::_main);
}

/*
 * Devolve o processador para a thread dispatcher que irá escolher outra thread pronta
 * para ser executada.
 */
void Thread::yield() {
    //imprima informação usando o debug em nível TRC
    db<Thread>(TRC) << "Thread chamou yield\n";

    //escolha uma próxima thread a ser executada
    Thread * next = Thread::_ready.remove()->object();

    //atualiza a prioridade da tarefa que estava sendo executada (aquela que chamou yield) com o
    //timestamp atual, a fim de reinserí-la na fila de prontos atualizada (cuide de casos especiais, como
    //estado ser FINISHING ou Thread main que não devem ter suas prioridades alteradas)
    Thread * prev = Thread::_running;
    if (prev->_state != FINISHING && prev->_id != 0) {

        prev->_state = READY;
        prev->_link.rank(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
        //reinsira a thread que estava executando na fila de prontos
        Thread::_ready.insert_tail(&prev->_link);
    }

    //atualiza o ponteiro _running
    Thread::_running = next;
    //atualiza o estado da próxima thread a ser executada
    next->_state = RUNNING;
    //troque o contexto entre as threads
    switch_context(prev, next);
    }

__END_API