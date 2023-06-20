#ifndef thread_h
#define thread_h

#include "cpu.h"
#include "traits.h"
#include "debug.h"
#include "list.h"
#include "semaphore.h"
#include <ctime>
#include <chrono>

__BEGIN_API

class Thread
{
protected:
    typedef CPU::Context Context;
public:
    typedef Ordered_List<Thread> Ready_Queue;
    typedef Ordered_List<Thread> Waiting_Queue;

    // Thread State
    enum State {
        RUNNING,
        READY,
        FINISHING,
        SUSPENDED,
        WAITING
    };

    /*
     * Construtor vazio. Necessário para inicialização, mas sem importância para a execução das Threads.
     */
    Thread() {}

    /*
     * Cria uma Thread passando um ponteiro para a função a ser executada
     * e os parâmetros passados para a função, que podem variar.
     * Cria o contexto da Thread.
     * PS: devido ao template, este método deve ser implementado neste mesmo arquivo .h
     */
    template <typename... Tn>
    Thread(void (*entry)(Tn...), Tn... an);

    /*
     * Retorna a Thread que está em execução.
     */
    static Thread *running();

    /*
     * Método para trocar o contexto entre duas thread, a anterior (prev)
     * e a próxima (next).
     * Deve encapsular a chamada para a troca de contexto realizada pela class CPU.
     * Valor de retorno é negativo se houve erro, ou zero.
     */
    static int switch_context(Thread *prev, Thread *next);

    /*
     * Termina a thread.
     * exit_code é o código de término devolvido pela tarefa (ignorar agora, vai ser usado mais tarde).
     * Quando a thread encerra, o controle deve retornar à main.
     */
    void thread_exit(int exit_code);

    /*
     * Retorna o ID da thread.
     */
    int id();

    /*
     * NOVO MÉTODO DESTE TRABALHO.
     * Daspachante (disptacher) de threads.
     * Executa enquanto houverem threads do usuário.
     * Chama o escalonador para definir a próxima tarefa a ser executada.
     */
    static void dispatcher();

    /*
     * NOVO MÉTODO DESTE TRABALHO.
     * Realiza a inicialização da class Thread.
     * Cria as Threads main e dispatcher.
     */
    static void init(void (*main)(void *));

    /*
     * Devolve o processador para a thread dispatcher que irá escolher outra thread pronta
     * para ser executada.
     */
    static void yield();

    /*
     * Deve suspender a Thread em execução até que a Thread alvo finalize
     */
    int join();

    /*
     * Suspende a Thread até que resume() seja chamado
     */
    void suspend();

    /*
     * Coloca Thread que estava suspensa de volta para a fila de prontos
     */
    void resume();

    /*
     * Destrutor de uma thread. Realiza todo os procedimentos para manter a consistência da classe.
     */
    ~Thread();

    /*
     * Retorna o contexto
     */
    Context * context();

    /*
     * Retorna o link da thread
    */
    Ready_Queue::Element link();

    /**
     * Coloca thread pra dormir
    */
    static void sleep(Waiting_Queue * waiting_queue);

    /*
     * Acorda thread
    */
    static void wakeup(Waiting_Queue * waiting_queue);

private:
    int _id = 0;
    Context * volatile _context;
    static CPU::Context _main_context;
    static Thread * _running;
    static Thread _main;
    static Thread _dispatcher;
    volatile State _state;
    static Ready_Queue _ready;
    static Ready_Queue _suspended;
    Ready_Queue::Element _link;
    // Nossos parâmetros
    Waiting_Queue * _waiting;
    int _exit_code;
    static int _counter;
    // Ponteiro para thread que está esperando(bloqueada)
    Thread * _join_callee;

};

template <typename... Tn>
inline Thread::Thread(void (*entry)(Tn...), Tn... an) : _link(this, (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count())) {
    this->_context = new CPU::Context(entry, an ...);
    this->_id = _counter++;
    if (_id > 0) {
        _ready.insert(&_link);
    }
    this->_state = READY;
    this->_join_callee = nullptr;
}

__END_API

#endif