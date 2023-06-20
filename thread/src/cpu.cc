#include <iostream>
#include "../include/cpu.h"

__BEGIN_API

void CPU::Context::save() {
    getcontext(&this->_context);
}

void CPU::Context::load() {
    setcontext(&this->_context);
}

int CPU::finc(volatile int &number) {
    int increment = 1;
    __asm__ __volatile__(
        "lock xadd %[increment], %[number]"
        : [increment] "+r"(increment), [number] "+m"(number)
        :
        : "memory");
    return number;
}

int CPU::fdec(volatile int &number) {
    int decrement = -1;
    __asm__ __volatile__(
        "lock xadd %[decrement], %[number]"
        : [decrement] "+r"(decrement), [number] "+m"(number)
        :
        : "memory");
    return number;
}

CPU::Context::~Context() {
    if (_stack) { 
        delete (_stack);
    }
}

int CPU::switch_context(Context *from, Context *to) {
    return swapcontext(&from->_context, &to->_context);
}

__END_API
