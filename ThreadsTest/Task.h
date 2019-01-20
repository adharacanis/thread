//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#ifndef THREADSTEST_TASK_H
#define THREADSTEST_TASK_H

#include "Runable.h"

class Task: public Runable {

public:
    void run() override;

    ~Task() override;

    int value = 0;
};


#endif //THREADSTEST_TASK_H
