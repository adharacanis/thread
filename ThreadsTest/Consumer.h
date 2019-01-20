//
// Created by Konstantin Klementiev on 2019-01-20.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#ifndef THREADSTEST_CONSUMER_H
#define THREADSTEST_CONSUMER_H


#include "Runable.h"
#include "MonitorQueue.h"

class Consumer: public Runable {
public:
    Consumer(int);
    ~Consumer() override;

    void run() override;

    void setQueMonitor(MonitorQueue*);

private:
    MonitorQueue * m_queMonitor;
    vector<int> consumed;
    int m_consumesCount;

    void consume(int);
};


#endif //THREADSTEST_CONSUMER_H
