#ifndef QUETYPE_H
#define QUETYPE_H

using namespace std;
#include <stdexcept>
class QueType
{
    private:
        int* array;
        int rear;
        int capacity;
    public:
        QueType(int size) : capacity(size), rear(0) {array = new int[capacity];}
        ~QueType() {delete[] array;}
        bool isEmpty() const
        {
            return rear == 0;
        }
        bool isFull() const
        {
            return rear == capacity;
        }
        int size() const
        {
            return rear;
        }
        void Enqueue(int item)
        {
            if(rear == capacity){
                throw std::overflow_error("Queue is full");
            }
            array[rear] = item;
            rear++;
        }
        int Dequeue()
        {
            if(rear == 0)
            {
                throw std::underflow_error("Queue is empty");
            }
            int item = array[0];
            for(int i = 0; i < rear - 1; i++)
            {
                array[i] = array[i+1];
            }
            rear--;
            return item;
        }
};
#endif