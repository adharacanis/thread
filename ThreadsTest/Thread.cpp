//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#include "Thread.h"
#include "Runable.h"

using namespace std;

Thread::~Thread() {

}

Thread::Thread(Runable * runable) {
    m_runable = runable;

    thread l_runable(&Runable::run, runable);
    m_runableThread = &l_runable;
    m_runableThread->detach();
}

void Thread::join() {
    m_runableThread->join();
}
