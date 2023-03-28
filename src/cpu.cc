#include "../include/cpu.h"
#include <iostream>

__BEGIN_API

void CPU::Context::save()
{
    getcontext(&this->_context);
}

void CPU::Context::load()
{
    setcontext(&this->_context);
}

CPU::Context::~Context()
{
    try { 
        delete (_stack);}
    catch(...) { 
        std::cout << "Não existe uma pilha";}
}

int CPU::switch_context(Context *from, Context *to)
{
    return swapcontext(&from->_context, &to->_context);
}

__END_API
