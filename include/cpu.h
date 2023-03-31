#ifndef cpu_h
#define cpu_h

#include <ucontext.h>
#include <iostream>
#include "traits.h"

__BEGIN_API

class CPU
{
    public:

        class Context
        {
        private:
            static const unsigned int STACK_SIZE = Traits<CPU>::STACK_SIZE;
        public:
            Context() { _stack = 0; }

            template<typename ... Tn>
            Context(void (* func)(Tn ...), Tn ... an);

            ~Context();

            void save();
            void load();

        private:            
            char *_stack;
        public:
            ucontext_t _context;
        };

    public:

        static int switch_context(Context *from, Context *to);

};

template<typename ... Tn> CPU::Context::Context(void (* func)(Tn...), Tn ... an)
{
    try { 
        getcontext(&_context);
        _stack = new char[STACK_SIZE];
        _context.uc_stack.ss_sp = &_stack;
        _context.uc_stack.ss_size = STACK_SIZE;
        _context.uc_link = &_context;
        makecontext(&_context, (void (*)()) func, (int)sizeof...(an), an...);}
    catch (...) {
        std::cout << "Erro ao tentar fazer o contexto.";}
}

__END_API

#endif

