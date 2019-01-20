//
//  main.cpp
//  ThreadsTest
//
//  Created by Konstantin Klementiev on 2019-01-19.
//  Copyright © 2019 Konstantin Klementiev. All rights reserved.
//

#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Task.h"
#include "Thread.h"
#include "Producer.h"
#include "Consumer.h"

using namespace std;

template <typename C>
void printVector(const C& c) {
    for(const auto& e:c) {
        cout << e << " ";
    }
    cout << endl;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortByBubble(vector<int>& arr) {
    int i, j;
    for (i = 0; i < arr.size()-1; i++) {
        for (j = 0; j < arr.size()-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    //int data[5] = {1, 2, 3, 4, 5};
    //cout << sizeof(data) << " " << sizeof(data[0]) << endl << endl;

    int numberOfProducts, minProductValue, maxProductValue, monitorSize;
    cout << "enter data: {numberOfProducts} {minProductValue} {maxProductValue} {monitorSize}" << endl;
    cin >> skipws >> numberOfProducts >> minProductValue >> maxProductValue >> monitorSize;
    cout << numberOfProducts << ", " << minProductValue << ", " << maxProductValue << endl;

    Producer * producer = new Producer(numberOfProducts, minProductValue, maxProductValue);
    //producer->fillThoughts(data, sizeof(data)/sizeof(data[0]));

    Consumer * consumer = new Consumer(numberOfProducts);

    cout << this_thread::get_id() << " main thread " << endl << endl;

    MonitorQueue monitorQue(monitorSize);

    producer->setQueMonitor(&monitorQue);
    consumer->setQueMonitor(&monitorQue);

    Thread producerThread(producer);
    Thread consumerThread(consumer);

    //producerThread.join();
    //consumerThread.join();

    while(producer->isRunned() && consumer->isRunned()) {
        this_thread::sleep_for(chrono::microseconds(1000));
    }

    cout << "produce and consume is over" << endl;

    return 0;
}