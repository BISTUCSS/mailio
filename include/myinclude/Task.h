//
// Created by c w on 2021/12/10.
//

#ifndef MAILIO_TASK_H
#define MAILIO_TASK_H


class Task {

    int id;

    static int count;

public:

    Task();

    int getId();

    virtual void execute() = 0;

    virtual bool is_finish() = 0;

};




#endif //MAILIO_TASK_H
