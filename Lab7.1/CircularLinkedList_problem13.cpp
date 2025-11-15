//Jakobe McPhail
//11/11/25
//Data Structures
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

int countLength(CNode* current, CNode* stop)
{
    if(current->next == stop)
    {
        return 1;
    }
    return 1 + countLength(current->next, stop);
}

int getLength(CNode* head)
{
    if(head == nullptr)
    {
        return 0;
    }
    if(head->next == head)
    {
        return 1;
    }
    return countLength(head, head);
}

/*Recursive: Time:(O(n)), Space:(O(n)), function calls itself n times 
  Iterative: Time:(O(n)), Space:(O(1)), fast/slow pointer finds the meeting point in O(n) time
*/

int main()
{
    CircularLinkedList C1;
    C1.insert(1);
    C1.insert(2);
    C1.insert(3);
    C1.insert(4);
    C1.insert(5);

    std::cout << "Original: ";
    C1.print();

    std::cout << std::endl;
    int length = getLength(C1.head);
    std::cout << "List Length: " << length;
}