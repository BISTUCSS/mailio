//
// Created by c w on 2021/12/10.
//
#include "iostream"
#include "myinclude/BaseThread.h"
#include "myinclude/TaskAllocator.h"
#include "myinclude/TaskThread.h"
using std::cout;
using std::endl;

TaskAllocator::TaskAllocator() {
}

void TaskAllocator::add_thread(TaskThread* thread) {
    thread_list.push_back(thread);
}

void TaskAllocator::start_work() {

    for(int i = 0; i < thread_list.size(); i++){
        printf("thread %d start\n", thread_list[i]->get_id());
        thread_list[i]->start();
    }

    while(1) {

        if (!task_queue.is_empty()) {
            Task *task = this->task_queue.front();
            bool flag = false;
            for (int i = 0; i < thread_list.size(); i++) {
                if (thread_list[i]->is_idle()) {
                    printf("task %d assign to thread %d\n", task->getId(),thread_list[i]->get_id());
                    thread_list[i]->assign_task(*task);
                    thread_list[i]->wake_up();
                    flag = true;
                    break;
                }
            }
            if(flag) {
                task_queue.pop();
            }
        }

    }

}

void TaskAllocator::receive_task(Task &task) {
    this->task_queue.push(&task);
}
