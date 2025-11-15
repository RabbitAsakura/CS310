//Jakobe McPhail
//11/11/25
//Data Structures
#include "Stack.h"
#include <iostream>
using namespace std;

void bottom(Stack& s, int val)
{
    if(s.isEmpty())
    {
        s.push(val);
        return;
    }
    int temp = s.pop();
    bottom(s, val);
    s.push(temp);
}

void Reverse(Stack& s)
{
    if(s.isEmpty())
    {
        return;
    }
    int temp = s.pop();
    Reverse(s);
    bottom(s, temp);
}

/*Recursive: Time:(O(n^2)), Space:(O(n^2)), two function calls itself n times so n * n
  Iterative: Time:(O(n)), Space:(O(n)), pop all n items onto a queue->then put enqueue them back into the stack
*/

int main()
{
    Stack S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    
    
    Reverse(S1);
    std::cout << "Reverse: ";
    while(!S1.isEmpty())
    {
        std::cout << S1.pop() << " ";
    }
}