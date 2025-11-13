//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"


class Stack
{
    public:
        Node* top;
        Stack() : top(nullptr) {}
        void push(int val);
        int pop();
        bool isEmpty();
};

#endif