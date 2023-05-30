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
    Thread *sleep_thread = Thread::running();
    // Coloca a thread atual na fila de espera e deixa ela dormindo
    Thread::Ready_Queue::Element link_ptr = sleep_thread->link();
    _waiting_queue.insert(&link_ptr);
    sleep_thread->sleep();
}

void Semaphore::wakeup() {
    // Acorda próxima thread da fila
    if (_waiting_queue.size() != 0) {
        Thread *first = _waiting_queue.remove()->object();
        db<Semaphore>(TRC) << "Wakeup [" << first->id() << "]\n";
        first->wakeup();
        
    }
}

void Semaphore::wakeup_all() {
    db<Semaphore>(TRC) << "Semaphore wake up all\n";
    // Acorda todas as threads na fila de espera
    while (_waiting_queue.size() > 0) {
        wakeup();
    }
}

__END_API