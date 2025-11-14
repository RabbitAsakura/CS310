//Jakobe McPhail
//11/11/25
//Data Structures
#include "Stack.h"
#include <iostream>
using namespace std;


void sorted(Stack& s, int val)
{
    if(s.isEmpty() || val < s.peek())
    {
        s.push(val);
        return;
    }

    int temp = s.pop();
    sorted(s, val);
    s.push(temp);
}

void sortStack(Stack& s)
{
    if (s.isEmpty())
    {
        return;
    }

    int temp = s.pop();
    sortStack(s);
    sorted(s, temp);
}


int main()
{
    Stack S1;
    S1.push(25);
    S1.push(75);
    S1.push(100);
    S1.push(1);
    S1.push(0);

    sortStack(S1);

    std::cout << "Sorted Stack: ";
    while(!S1.isEmpty())
    {
        std::cout << S1.pop() << " ";
    }
    std::cout << std::endl;

}