//
// Created by c w on 2021/12/11.
//

#ifndef MAILIO_CONCURRENTQUEUE_H
#define MAILIO_CONCURRENTQUEUE_H


#include "queue"
#include "pthread.h"

template<class T>
class ConcurrentQueue {

    std::queue<T> queue;

    pthread_mutex_t  mutex;

public:

    ConcurrentQueue();

    T front();

    int size();

    void pop();

    void push(T t);

    bool is_empty();
};

template<class T>
ConcurrentQueue<T>::ConcurrentQueue() {
    pthread_mutex_init(&mutex, NULL);
}

template<class T>
T ConcurrentQueue<T>::front() {
    pthread_mutex_lock(&mutex);
    T front = queue.front();
    pthread_mutex_unlock(&mutex);
    return front;
}

template<class T>
int ConcurrentQueue<T>::size() {
    pthread_mutex_lock(&mutex);
    int size = queue.size();
    pthread_mutex_unlock(&mutex);
    return size;
}

template<class T>
void ConcurrentQueue<T>::pop() {
    pthread_mutex_lock(&mutex);
    queue.pop();
    pthread_mutex_unlock(&mutex);
}

template<class T>
bool ConcurrentQueue<T>::is_empty() {
    pthread_mutex_lock(&mutex);
    bool is_empty = queue.empty();
    pthread_mutex_unlock(&mutex);
    return is_empty;
}

template<class T>
void ConcurrentQueue<T>::push(T t) {
    pthread_mutex_lock(&mutex);
    queue.push(t);
    pthread_mutex_unlock(&mutex);
}
#endif //MAILIO_CONCURRENTQUEUE_H
