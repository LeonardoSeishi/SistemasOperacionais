#include "../include/semaphore.h"
#include <iostream>

__BEGIN_API

void Semaphore::p() {
    if (fdec(_counter) < 0) {
        sleep();
    }
}

void Semaphore::v() {
    if (finc(_counter) < 1) {
        wakeup();
    }
}

int Semaphore::finc(volatile int &number) {
    return 0;
}

int Semaphore::fdec(volatile int &number) {
    return 0;
}

void Semaphore::sleep() {
    Thread *sleep_thread = Thread::running();
    // Coloca a thread atual na fila de espera e deixa ela dormindo
    _waiting_queue.insert(&sleep_thread->link());
    sleep_thread->sleep();
}

void Semaphore::wakeup() {
    // Acorda próxima thread da fila
    if (_waiting_queue.size() != 0) {
        Thread *first = _waiting_queue.remove()->object();
        first->wakeup();
    }
}

void Semaphore::wakeup_all() {
    // Acorda todas as threads na fila de espera
    while (_waiting_queue.size() > 0) {
        wakeup();
    }
}

__END_API