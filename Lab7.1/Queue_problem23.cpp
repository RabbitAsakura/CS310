//Jakobe McPhail
//11/14/25
//Data Structures
#include "Stack.h"
#include <iostream>
using namespace std;

void transfer(Stack& s1, Stack& s2)
{
    if (s1.isEmpty())
    {
        return;
    }
    s2.push(s1.pop());
    transfer(s1, s2);
}

void enqueue(Stack& s1, int val)
{
    s1.push(val);
}

int dequeue(Stack& s1, Stack& s2)
{
    if (s1.isEmpty() && s2.isEmpty())
    {
        throw std::runtime_error("Queue is empty.");
    }

    if (s2.isEmpty())
    {
        transfer(s1, s2);
    }
    return s2.pop();
}

/*Recursive: Time:(O(n)), Space:(O(n)), if a stack is empty->a function is called that runs n times
  Iterative: Time:(O(1)), Space:(O(1)), it is a push
*/

int main()
{
    Stack Q1;
    Stack Q2;

    enqueue(Q1, 1);
    enqueue(Q1, 2);
    enqueue(Q1, 3);

    std::cout << "Dequeueing: " << dequeue(Q1, Q2) << std::endl;
    enqueue(Q1, 5);
    std::cout << "Dequeueing: " << dequeue(Q1, Q2) << std::endl;
    std::cout << "Dequeueing: " << dequeue(Q1, Q2) << std::endl;
}