//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include <iostream>
#include <stdexcept>

class Queue
{
    public:
        Node* front;
        Node* rear;
        Queue() : front(nullptr) , rear(nullptr) {}
        ~Queue()
        {
            while(!isEmpty())
            {
                dequeue();
            }
        }

        void enqueue(int val)
        {
            Node* newNode = new Node(val);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
       }
        int dequeue()
        {
            if (isEmpty())
        {
            throw std::runtime_error("Underflow ERROR");
        }
        int val = front->data;
        Node* temp = front;

        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        return val;
        }
        bool isEmpty() {return front == nullptr;}

        void print()
      {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
#endif