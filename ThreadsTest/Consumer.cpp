//
// Created by Konstantin Klementiev on 2019-01-20.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#include "Consumer.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

Consumer::Consumer(int consumesCount) {
    m_consumesCount = consumesCount;
}

Consumer::~Consumer() {

}

void Consumer::run() {
    Runable::run();

    cout << "run consumer thread" << endl;
    __thread_id threadName = this_thread::get_id();

    while(consumed.size() < m_consumesCount) {
        cout << threadName << " attempt to consume thoughts if it in queue " << endl;

        consume(m_queMonitor->removeHead());

        cout << threadName << " product consumed " << endl << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    m_runned = false;
}

void Consumer::consume(int value) {
    consumed.push_back(value);
}

void Consumer::setQueMonitor(MonitorQueue * value) {
    m_queMonitor = value;
}