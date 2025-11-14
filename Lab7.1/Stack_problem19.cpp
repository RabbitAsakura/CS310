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

int main()
{
    Stack S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    std::cout << "Original: ";
    while(!S1.isEmpty())
    {
        std::cout << S1.pop() << " ";
    }

    std::cout << std::endl;

    //Reverse(S1);
    std::cout << "Reverse: ";
    Reverse(S1);
    while(!S1.isEmpty())
    {
        std::cout << S1.pop() << " ";
    }
}