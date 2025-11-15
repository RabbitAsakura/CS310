//Jakobe McPhail
//11/14/25
//Data Structures
#include "Queue.h"
#include <iostream>
using namespace std;

void interleaveRecursive(Queue& q, Queue& helper_q, int count)
{
    if (count == 0)
    {
        return;
    }

    q.enqueue(helper_q.dequeue());
    
    q.enqueue(q.dequeue());

    interleaveRecursive(q, helper_q, count - 1);
}

void interleave(Queue& q)
{
    int n = 0;
    Queue temp_q;
    while (!q.isEmpty())
    {
        n++;
        temp_q.enqueue(q.dequeue());
    }
    while (!temp_q.isEmpty()) {
        q.enqueue(temp_q.dequeue());
    }

    if (n < 2) return; 

    Queue helper_q;

    int half_size = n / 2;
    for (int i = 0; i < half_size; ++i)
    {
        helper_q.enqueue(q.dequeue());
    }

    interleaveRecursive(q, helper_q, half_size);

    if (n % 2 != 0)
    {
        q.enqueue(q.dequeue());
    }
}

int main()
{
    Queue Q1;
    Q1.enqueue(1); Q1.enqueue(2); Q1.enqueue(3);
    Q1.enqueue(4); Q1.enqueue(5); Q1.enqueue(6);
    
    std::cout << "Original: ";
    Q1.print(); 

    interleave(Q1);
    std::cout << std::endl;
    
    std::cout << "Interleaved: ";
    Q1.print(); 
}