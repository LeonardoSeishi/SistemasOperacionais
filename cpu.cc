#include "cpu.h"
#include <iostream>

__BEGIN_API

void CPU::Context::save()
{
    getcontext();
}

void CPU::Context::load()
{
    setcontext();
}

CPU::Context::~Context()
{
    if (_stack) {       //Se existe uma pilha
        delete (_stack);//deletar a pilha
    }
}

int CPU::switch_context(Context *from, Context *to)
{
     swapcontext();
}

__END_API
