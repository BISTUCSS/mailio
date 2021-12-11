//
// Created by c w on 2021/12/10.
//

#include "iostream"
#include <thread>
#include <unistd.h>
#include "queue"
#include "mutex"
#include "condition_variable"
#include "pthread.h"

using std::cout;
using std::endl;


std::mutex mut;
std::queue<int> data_queue;  // 1
std::condition_variable data_cond;


void data_preparation_thread() {
    pthread_mutex_t mutex;

//    pthread_t pthread;

    pthread_mutex_init(&mutex, nullptr);

    pthread_mutex_lock(&mutex);


    //todo



//    pthread_mutex_unlock(&wait_mutex);

    while (1) {
        int const data = 1;
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);  // 2
        data_cond.notify_one();  // 3
    }
}

void data_processing_thread() {
    while (true) {
        std::unique_lock<std::mutex> lk(mut);  // 4
        data_cond.wait(
                lk, [] { return !data_queue.empty(); });  // 5
        int data = data_queue.front();
        data_queue.pop();
        lk.unlock();  // 6
        cout << data << endl;

    }
}


int shared = 0;
pthread_mutex_t mutex;


void *runnable(void *arg) {
//    printf( "This is a thread and arg = %d.\n", *(int*)arg);


//    pthread_t pthread;

    usleep(10000);


    pthread_mutex_lock(&mutex);

//    pthread_mutex_unlock(&wait_mutex);
    shared++;

    pthread_mutex_unlock(&mutex);

    return arg;
}

#include "myinclude/ConcurrentQueue.h"


int main() {


    ConcurrentQueue<int> queue;

    queue.size();

    pthread_t th;
    int ret;
    int arg = 10;
    int *thread_ret = NULL;

    pthread_mutex_init(&mutex, nullptr);

    for (int i = 0; i < 1000; i++) {
        ret = pthread_create(&th, NULL, runnable, &arg);
    }

    sleep(5);

    cout << shared << endl;


}