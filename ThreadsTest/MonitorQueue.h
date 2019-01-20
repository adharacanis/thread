//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#ifndef THREADSTEST_MONITORQUEUE_H
#define THREADSTEST_MONITORQUEUE_H

#include <vector>
#include <mutex>

using namespace std;

class MonitorQueue {
public:
    MonitorQueue(int);

    virtual ~MonitorQueue();

    void addTail(int);
    int removeHead();

private:
    vector<int> queue;
    int m_size;
    mutex queMutex;
};


#endif //THREADSTEST_MONITORQUEUE_H
