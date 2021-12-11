//
// Created by c w on 2021/12/10.
//

#include <unistd.h>
#include "myinclude/BaseThread.h"
#include "myinclude/Task.h"
#include "myinclude/TaskAllocator.h"
#include "myinclude/BaseThread.h"

#include "signal.h"

using std::cout;
using std::endl;

class IdTask : public Task {
    bool is_finished;
public:

    IdTask();

    void execute() override;

    bool is_finish() override;

};


IdTask::IdTask() {
    is_finished = false;
}

void IdTask::execute() {
    printf("%d\n",getId());

    is_finished = true;
}

bool IdTask::is_finish() {
    return is_finished;
}

#include "myinclude/TaskAllocatorThread.h"

void initAllocatorThread(TaskAllocatorThread* taskAllocatorThread) {
    for(int i = 0; i < 10; i++) {
        taskAllocatorThread->add_task_thread(*new TaskThread());
    }
}

void handler(int a) {
    cout << a << endl;
}


int main() {
    signal(SIGINT, handler);

    TaskAllocatorThread *taskAllocatorThread = new TaskAllocatorThread();

    initAllocatorThread(taskAllocatorThread);

    taskAllocatorThread->start();

    for (int i = 0; i < 40; i++) {

        taskAllocatorThread->receive_task(*(new IdTask()));

        usleep(1000000 );

    }

    while (1) {

    }

}