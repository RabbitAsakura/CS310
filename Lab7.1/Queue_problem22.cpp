//Jakobe McPhail
//11/14/25
//Data Structures
#include "Queue.h"
#include <iostream>
using namespace std;

void Reverse(Queue& q)
{
    if(q.isEmpty())
    {
        return;
    }
    int temp = q.dequeue();
    Reverse(q);
    q.enqueue(temp);
}


int main()
{
    Queue Q1;
    Q1.enqueue(5);
    Q1.enqueue(7);
    Q1.enqueue(9);
    Q1.enqueue(10);
    Q1.enqueue(12);
    Q1.enqueue(13);

    std::cout << "Original: ";
    Q1.print();

    std::cout << std::endl;
    Reverse(Q1);
    std::cout << "Reverse: ";
    Q1.print();
}