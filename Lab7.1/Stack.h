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
        ~Stack()
        {
            while(!isEmpty())
            {
                pop();
            }
        }

        void push(int val)
        {
            Node* newNode = new Node(val);
            newNode->next = top;
            top = newNode;
        }
        int pop()
        {
            if(isEmpty())
            {
                throw std::runtime_error("Underflow Error");
            }

            int val = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return val;
        }
        bool isEmpty() {return top == nullptr;}
        int peek()
        {
            if(isEmpty())
            {
                throw std::runtime_error("Underflow Error");
            }
            return top->data;
        }
};
#endif