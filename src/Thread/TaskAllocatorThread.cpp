//
// Created by c w on 2021/12/11.
//

#include "myinclude/TaskAllocatorThread.h"


TaskAllocatorThread::TaskAllocatorThread()
{
    taskAllocator = new TaskAllocator();
}

void TaskAllocatorThread::receive_task(Task& task) {
    taskAllocator->receive_task(task);
}

void TaskAllocatorThread::add_task_thread(TaskThread& taskThread) {
    taskAllocator->add_thread(&taskThread);
}

void TaskAllocatorThread::run() {
    taskAllocator->start_work();
}


