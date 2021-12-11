//
// Created by c w on 2021/12/10.
//

#ifndef MAILIO_TASKALLOCATOR_H
#define MAILIO_TASKALLOCATOR_H

#include "vector"
#include "iostream"
#include "queue"
#include "mutex"
#include "myinclude/TaskThread.h"
#include "myinclude/ConcurrentQueue.h"

class TaskAllocator {

    ConcurrentQueue<Task *> task_queue;
    std::vector<TaskThread *> thread_list;
    std::mutex mutex;

public:

    TaskAllocator();

    void add_thread(TaskThread* thread);

    void start_work();

    void receive_task(Task &task);
};


#endif //MAILIO_TASKALLOCATOR_H
