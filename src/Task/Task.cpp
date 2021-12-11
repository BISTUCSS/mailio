//
// Created by c w on 2021/12/11.
//

#include "myinclude//Task.h"

int Task::count = 0;

Task::Task() {
    id = count++;
}

int Task::getId() {
    return id;
}