#include "../include/thread.h"
#include "../include/cpu.h"
#include <iostream>
#include <chrono>

__BEGIN_API

CPU::Context Thread::_main_context;

Thread * Thread::_running = nullptr;
Thread Thread::_main;
Thread Thread::_dispatcher;
Thread::Ready_Queue Thread::_ready;
Thread::Ready_Queue Thread::_suspended;

int Thread::_counter = 0;


// FUNÇÕES

int Thread::id() { return Thread::_id; }

Thread * Thread::running() { 
    return _running; 
}

int Thread::switch_context(Thread * prev, Thread * next) {
    if (prev->id() != next->id()) {
        _running = next;
        return CPU::switch_context(prev->context(), next->context());
    } else {
        return 0;
    }
}

void Thread::thread_exit(int exit_code) {
    _exit_code = exit_code;
    _counter = _counter - 1;
    // Modifica estado
    _state = FINISHING;
    // Resume execucao da thread que estava esperando
    if (this->_join_callee != nullptr) {
        this->_join_callee->resume();
    }
    // Sinaliza escalonador
    yield();
}

CPU::Context * Thread::context() { return _context; };

Thread::~Thread() {
    db<Thread>(TRC) << "Thread [" << id() << "] removida.\n";
    // Remove thread da fila de prontos
    _ready.remove(this);
    if(_context) {
        delete _context;
        
    }
}

void Thread::init(void (*main)(void*)) {

    // Inicializar thread Main passando como parametro o ponteiro da funcao main
    new (&_main) Thread(main, (void*) "Main");
    new (&_main_context) CPU::Context();
    // Inicializar thread Dispatcher
    new (&_dispatcher) Thread((void (*)(void *)) & Thread::dispatcher, (void *)NULL);
    // Atualiza estado da main
    _running = &_main;
    _main._state = RUNNING;
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
    while (_counter > 2) {
        // Escolhe proxima thread a ser executada
        Thread *first = _ready.remove()->object();
        // Atualiza status da propia thread dispatcher pra READY e reinsere a mesma em _ready
        _dispatcher._state = READY;
        _ready.insert(&_dispatcher._link);
        // Atualiza o ponteiro _running para apontar para a proxima thread a ser executada
        _running = first;
        // Atualiza o estado da proxima thread a ser executada
        first->_state = RUNNING;
        // Troca o contexto entre as duas threads
        db<Thread>(TRC) << "Thread [" << first->_id <<"] executando.\n";
        switch_context(&_dispatcher, first);
        // Testa se o estado da proxima thread eh FINISHING e caso afirmativo remove de _ready
        if (first->_state == FINISHING) {
            _ready.remove(first);
        }
    }
    // Muda o estado da thread dispatcher para FINISHING
    Thread::_dispatcher._state = FINISHING;
    // Remove a thread dispatcher da fila de prontos
    Thread::_ready.remove(&_dispatcher);
    // Troca o contexto de dispatcher para main
    db<Thread>(TRC) << "Dispatcher removida\n";
    Thread::switch_context(&_dispatcher, &_main);
}

/*
 * Devolve o processador para a thread dispatcher que irá escolher outra thread pronta
 * para ser executada.
 */
void Thread::yield() {
    //imprima informação usando o debug em nível TRC
    db<Thread>(TRC) << "Thread [" << _running->id() << "] chamou yield\n";

    // Checa se thread é bloqueante
    if (_running->_state == FINISHING && _running->_join_callee != nullptr) {
        // Libera thread bloqueada
        _running->_join_callee->resume();
    }
    //escolha uma próxima thread a ser executada
    Thread * next = _ready.remove()->object();

    //atualiza a prioridade da tarefa que estava sendo executada (aquela que chamou yield) com o
    //timestamp atual, a fim de reinserí-la na fila de prontos atualizada (cuide de casos especiais, como
    //estado ser FINISHING ou Thread main que não devem ter suas prioridades alteradas)
    Thread * prev = _running;
    if (prev->_state != FINISHING && prev->_id != 0) {

        prev->_state = READY;
        prev->_link.rank(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
        //reinsira a thread que estava executando na fila de prontos
        _ready.insert(&prev->_link);
    }

    //atualiza o ponteiro _running
    _running = next;
    //atualiza o estado da próxima thread a ser executada
    next->_state = RUNNING;
    //troque o contexto entre as threads
    switch_context(prev, next);
}

int Thread::join() {
    db<Thread>(TRC) << "Thread [" << _running->id()  <<"] chamou join em [" << this->id() << "]\n";
    if (this->_state == FINISHING) {
        return _exit_code; 
    }
    // Salva ponteiro de thread bloqueada em thread bloqueante
    Thread * prev = _running;
    // this->_state = READY;
    this->_join_callee = prev;
    // Suspende thread bloqueada
    prev->suspend();

    return _exit_code;
};

void Thread::suspend() {
    db<Thread>(TRC) << "Thread [" << this->_id << "] suspensa\n";
    _state = SUSPENDED;
    _suspended.insert(&this->_link);
    if (_running == this) {
        yield();
    } else {
        _ready.remove(this);
    }
};

void Thread::resume() {
    _suspended.remove(this);
    db<Thread>(TRC) << "Thread [" << this->_id << "] resumindo execução\n";
    this->_state = READY;
    this->_ready.insert(&this->_link);
};

__END_API