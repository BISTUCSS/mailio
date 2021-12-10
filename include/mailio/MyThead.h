//
// Created by wc on 2021/12/9.
//

#include <thread>
#include "iostream"
#ifndef MAILIO_MYTHEAD_H
#define MAILIO_MYTHEAD_H
using namespace std;
class Thread {
private:

    int a;
    std::thread *th;

public :

    Thread(int a)  {
        this->a = a;
    }

    void run2() {
        run();
        cout << a << endl;
    }

    virtual void run() = 0;

    ~Thread() {
        cout << "des" << endl;
    }

    void start() {

        th = new std::thread(&Thread::run2, this);

    }
};



#endif //MAILIO_MYTHEAD_H
