//Jakobe McPhail
//12/04/25
//Data Structures
#ifndef HEAPMASTER_H
#define HEAPMASTER_H
#include <iostream>
#include <iomanip>
#include <cstring>

struct Task
{
    int id;
    int priority;
    int arrivalTime;
    int burstTime;
    int deadline;
    void print() const
    {
        std::cout << "Task#" << id
                  << " pri=" << priority
                  << " arrive=" << arrivalTime
                  << " burst=" << burstTime
                  << " dead=" << deadline;
    }
};

template<typename T, int MAX_SIZE = 1000005, typename Compare = std::less<T>>
class HeapMaster
{
    private:
        T data[MAX_SIZE];
        int sz;
        Compare comp;

        int parent(int i) const {return (i - 1) / 2;}
        int left(int i) const {return 2 * i + 1;}
        int right(int i) const {return 2 * i + 2;}
        
        void heapifyUp(int i);
        void heapifyDown(int i);
    
    public:
        HeapMaster() : sz(0) {}

        bool empty() const {return sz == 0;}
        int size() const {return sz;}
        const T& top() const;

        void push(const T& value);
        void pop();
        void clear() {sz = 0;}
        
        bool decreaseKey(int index, const T& newVal);
        bool increaseKey(int index, const T& newVal);

        void printHeap() const;
        void printArray() const;
};

#include "HeapMaster.hpp"
#endif