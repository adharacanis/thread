//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#include "Producer.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Producer::Producer(int produceCount, int minValue, int maxValue) {
    for(int i = 0; i < produceCount; i++) {
        thoughts.push_back(rand() % maxValue + minValue);
    }
}

Producer::~Producer() {

}

void Producer::run() {
    Runable::run();

    __thread_id threadName = this_thread::get_id();

    while(thoughts.size() > 0) {
        int product = thoughts.back();
        thoughts.pop_back();

        cout << threadName << " producer product: " << product << endl;
        m_queMonitor->addTail(product);

        this_thread::sleep_for(chrono::seconds(3));
    }

    m_runned = false;
}

void Producer::fillThoughts(int data[], int len) {
    cout << "fill producer thoughts: " << len << endl;
    for(int i = 0; i < len; i++) {
        thoughts.push_back(data[i]);
    }
}

void Producer::setQueMonitor(MonitorQueue * value) {
    m_queMonitor = value;
}
