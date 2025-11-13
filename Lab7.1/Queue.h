//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

class Queue
{
    public:
        Node* front;
        Node* rear;
        Queue() : front(nullptr) , rear(nullptr) {}
        void enqueue(int val);
        int dequeue();
        bool isEmpty();
};


#endif