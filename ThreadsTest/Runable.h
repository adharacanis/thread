//
// Created by Konstantin Klementiev on 2019-01-19.
// Copyright (c) 2019 ___FULLUSERNAME___. All rights reserved.
//

#ifndef THREADSTEST_RUNABLE_H
#define THREADSTEST_RUNABLE_H

class Runable {
public:
    virtual void run();
    virtual ~Runable(){};
    bool isRunned();

protected:
    bool m_runned;
};


#endif //THREADSTEST_RUNABLE_H
