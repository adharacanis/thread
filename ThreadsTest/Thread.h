//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#ifndef THREADSTEST_THREAD_H
#define THREADSTEST_THREAD_H


#include "Runable.h"
#include <thread>

class Thread {
public:
    Thread(Runable*);

    virtual ~Thread();

    void join();

private:
    Runable * m_runable;
    std::thread * m_runableThread;
};


#endif //THREADSTEST_THREAD_H
