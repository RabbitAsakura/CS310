//Jakobe McPhail
//11/14/25
//Data Structures
#include "Queue.h"
#include <iostream>
using namespace std;

void generateRec(Queue& Q, int n)
{
    if (n <= 0)
    {
        return;
    }

    int current = Q.dequeue();

    std::cout << current << " ";

    Q.enqueue(current * 10);

    Q.enqueue(current * 10 + 1);
    generateRec(Q, n - 1);
}

void generateBinary(int n)
{
    if (n <= 0) {return;}

    Queue q;
    q.enqueue(1);
    generateRec(q,n);
}

/*Recursive: Time:(O(n)), Space:(O(n)), queue grows to O(n), same as call stack
  Iterative: Time:(O(n)), Space:(O(n)), queue stores next numbers to be processed
*/

int main()
{
    int i = 10;
    std::cout << "Binary Number for " << i << ": ";
    generateBinary(i);
    std::cout << std::endl;
}