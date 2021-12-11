//
// Created by c w on 2021/12/11.
//

#include "pthread.h"
#include "myinclude/ConcurrentQueue.h"

//template<class T>
//ConcurrentQueue<T>::ConcurrentQueue() {
//    pthread_mutex_init(&wait_mutex, NULL);
//}
//
//template<class T>
//T ConcurrentQueue<T>::front() {
//    pthread_mutex_lock(&wait_mutex);
//    T front = queue.front();
//    pthread_mutex_unlock(&wait_mutex);
//    return front;
//}
//
//template<class T>
//int ConcurrentQueue<T>::size() {
//    pthread_mutex_lock(&wait_mutex);
//    int size = queue.size();
//    pthread_mutex_unlock(&wait_mutex);
//    return size;
//}
//
//template<class T>
//void ConcurrentQueue<T>::pop() {
//    pthread_mutex_lock(&wait_mutex);
//    queue.pop();
//    pthread_mutex_unlock(&wait_mutex);
//}
//
//template<class T>
//bool ConcurrentQueue<T>::is_empty() {
//    pthread_mutex_lock(&wait_mutex);
//    bool is_empty = queue.empty();
//    pthread_mutex_unlock(&wait_mutex);
//    return is_empty;
//}
//
//template<class T>
//void ConcurrentQueue<T>::push(T t) {
//    pthread_mutex_lock(&wait_mutex);
//    queue.push(t);
//    pthread_mutex_unlock(&wait_mutex);
//}


