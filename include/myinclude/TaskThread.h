//
// Created by c w on 2021/12/11.
//

#ifndef MAILIO_TASKTHREAD_H
#define MAILIO_TASKTHREAD_H

#include "myinclude/Task.h"
#include "pthread.h"
#include "myinclude/BaseThread.h"

class TaskThread : public BaseThread{

protected:

    Task* task = nullptr;

public:

    TaskThread();

    void assign_task(Task &task);

    void run();
};


#endif //MAILIO_TASKTHREAD_H
