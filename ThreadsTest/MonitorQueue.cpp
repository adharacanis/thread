//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#include "MonitorQueue.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

MonitorQueue::MonitorQueue(int size) {
    m_size = size;
}

MonitorQueue::~MonitorQueue() {

}

void MonitorQueue::addTail(int value) {
    __thread_id threadId = this_thread::get_id();

    cout << threadId << " addTail to monitor " << value << endl;
    while(queue.size() == m_size) {
        cout << threadId << " monitor que is full wait..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << threadId << " value added" << endl;
    cout << endl;

    lock_guard<mutex> guard(queMutex);
    queue.push_back(value);
}

int MonitorQueue::removeHead() {
    __thread_id threadId = this_thread::get_id();

    cout << threadId << " remove head from monitor, que size is: " << queue.size() << endl;
    while(queue.size() == 0) {
        cout << threadId << " monitor is empty so wait untill we have something" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    lock_guard<mutex> guard(queMutex);
    int retValue = queue.back();
    queue.pop_back();

    cout << threadId << " monitor return value " << retValue << endl;
    cout << endl;

    return retValue;
}