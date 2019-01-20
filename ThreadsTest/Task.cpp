//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#include "Task.h"
#include <iostream>

void Task::run() {
    Runable::run();

    std::cout << value;
}

Task::~Task() {

}
