#include "../include/semaphore.h"
#include <iostream>

__BEGIN_API

void Semaphore::p() {
    db<Semaphore>(TRC) << "Semaphore post: " << _counter << "\n";
    if (_counter == 0) {
        sleep();
    }
    fdec(_counter);
}

void Semaphore::v() {
    db<Semaphore>(TRC) << "Semaphore free: " << _counter << "\n";
    if (_counter < 1) {
        wakeup();
    }
    finc(_counter);
}

int Semaphore::finc(volatile int &number) {
    return CPU::finc(number);
}

int Semaphore::fdec(volatile int &number) {
    return CPU::fdec(number);
}

void Semaphore::sleep() {

    Thread::sleep(&_waiting_queue);
}


void Semaphore::wakeup() {

    Thread::wakeup(&_waiting_queue);
}

void Semaphore::wakeup_all() {
    db<Semaphore>(TRC) << "Semaphore wake up all\n";
    // Acorda todas as threads na fila de espera
    while (_waiting_queue.size() > 0) {
        wakeup();
    }
}

__END_API