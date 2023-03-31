#include <iostream>
#include "../include/cpu.h"

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
    if (_stack) { 
        delete (_stack);
    } else { 
        std::cout << "Não existe uma pilha";}
}

int CPU::switch_context(Context *from, Context *to)
{
    return swapcontext(&from->_context, &to->_context);
}

__END_API
