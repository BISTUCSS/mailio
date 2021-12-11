//
// Created by c w on 2021/12/11.
//

#include "myinclude/TaskThread.h"

TaskThread::TaskThread() {

}

void TaskThread::assign_task(Task &task) {
    this->task = &task;
}

void TaskThread::run() {
    while (true) {
        if (task == nullptr||task->is_finish()) {
            wait_for_task();
        }
        task->execute();
    }
}
