#ifndef thread_h
#define thread_h

#include "cpu.h"
#include "traits.h"
#include "debug.h"

__BEGIN_API

class Thread
{
protected:
    typedef CPU::Context Context;

public:
    /*
     * Cria uma Thread passando um ponteiro para a função a ser executada
     * e os parâmetros passados para a função, que podem variar.
     * Cria o contexto da Thread.
     * PS: devido ao template, este método deve ser implementado neste mesmo arquivo .h
     */ 
    template<typename ... Tn>
    Thread(void (* entry)(Tn ...), Tn ... an);

    /*
     * Retorna a Thread que está em execução.
     */ 
    static Thread * running() { return _running; }

    /*
     * Método para trocar o contexto entre duas thread, a anterior (prev)
     * e a próxima (next).
     * Deve encapsular a chamada para a troca de contexto realizada pela class CPU.
     * Valor de retorno é negativo se houve erro, ou zero.
     */ 
    static int switch_context(Thread * prev, Thread * next);

    /*
     * Termina a thread.
     * exit_code é o código de término devolvido pela tarefa (ignorar agora, vai ser usado mais tarde).
     * Quando a thread encerra, o controle deve retornar à main. 
     */  
    void thread_exit (int exit_code);

    /*
     * Retorna o ID da thread.
     */ 
    int id() { return _id; }

    /*
     * Qualquer outro método que você achar necessário para a solução.
     */

    /*Retorna o contexto*/
    Context * get_context();

    static void set_running(Thread * next) { _running = next; }

    void decrement_id() { _id--; }

    /*destrutor*/
    ~Thread();

private:
    int _id = 0;
    int _counter = 0;
    Context * volatile _context;
    static Thread * _running;

    /*
     * Qualquer outro atributo que você achar necessário para a solução.
     */ 
};

template<typename ... Tn>Thread::Thread(void (* entry)(Tn ...), Tn ... an) {
    this->_context = new CPU::Context(entry, an ...);
    this->_id = this->_counter++;
}

__END_API

#endif
