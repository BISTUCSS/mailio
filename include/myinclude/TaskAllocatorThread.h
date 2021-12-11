//
// Created by c w on 2021/12/11.
//

#ifndef MAILIO_TASKALLOCATORTHREAD_H
#define MAILIO_TASKALLOCATORTHREAD_H
#include "myinclude/BaseThread.h"
#include "myinclude/TaskAllocator.h"

class TaskAllocatorThread : public BaseThread {
private:

    TaskAllocator* taskAllocator;

public:

    TaskAllocatorThread();

    void receive_task(Task& task);

    void add_task_thread(TaskThread& taskThread);

    void run();
};


#endif //MAILIO_TASKALLOCATORTHREAD_H
