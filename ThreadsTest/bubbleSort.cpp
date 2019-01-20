//
//  main.cpp
//  ThreadsTest
//
//  Created by Konstantin Klementiev on 2019-01-19.
//  Copyright © 2019 Konstantin Klementiev. All rights reserved.
//
/*
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <algorithm>

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

int bubbleSort(int argc, const char * argv[]) {

    int len;

    cout << "enter array len" << endl;

    cin >> len;

    cout << "eneter array" << endl;

    vector<int> vectorValue;
    int value;
    cin >> skipws;
    for(int i = 0; i < len; i++) {
        cin >> value;
        vectorValue.push_back(value);
    }

    printVector(vectorValue);

    cout << "sort vector..." << endl;

    thread sortThread(sortByBubble, ref(vectorValue));

    printVector(vectorValue);
    sortThread.join();

    return 0;
}*/