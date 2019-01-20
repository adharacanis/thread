//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#ifndef THREADSTEST_PRODUCER_H
#define THREADSTEST_PRODUCER_H


#include "Runable.h"
#include "MonitorQueue.h"
#include <vector>

using namespace std;

class Producer: public Runable {
public:
    void run() override;
    Producer(int, int, int);
    ~Producer() override;
    void fillThoughts(int [], int len);
    void setQueMonitor(MonitorQueue*);

private:
    vector<int> thoughts;
    MonitorQueue * m_queMonitor;
};


#endif //THREADSTEST_PRODUCER_H
