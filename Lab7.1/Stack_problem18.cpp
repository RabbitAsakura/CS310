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

/*Recursive: Time:(O(n^2)), Space:(O(n^2)), sortStack is called n times and sorted is called n times thus n * n
  Iterative: Time:(O(n^2)), Space:(O(n)),  each element that is popped->move all n elements from the helper stack back
*/

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