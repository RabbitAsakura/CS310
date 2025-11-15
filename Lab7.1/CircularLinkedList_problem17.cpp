//Jakobe McPhail
//11/11/25
//Data Structures
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

CNode* Josephus(CNode* startNode, int k)
{
    if (startNode->next == startNode)
    {
        return startNode;
    }

    CNode* prev; 
    CNode* toDelete; 

    if (k == 1)
    {
        prev = startNode;
        while (prev->next != startNode)
        {
            prev = prev->next;
        }
        toDelete = startNode;
    }
    else
    {
        prev = startNode;
        for (int i = 0; i < k - 2; ++i)
        {
            prev = prev->next;
        }
        toDelete = prev->next;
    }
    CNode* newStart = toDelete->next;

    prev->next = newStart;
    std::cout << "Eliminating: " << toDelete->data << std::endl;
    delete toDelete;

    return Josephus(newStart, k);
}

/*Recursive: Time:(O(n * k)), Space:(O(n)), recursion makes n calls
  Iterative: Time:(O(n * k)), Space:(O(1)), only use pointers
*/

int main()
{
    CircularLinkedList C1;
    C1.insert(6);
    C1.insert(5);
    C1.insert(4);
    C1.insert(3);
    C1.insert(2);
    C1.insert(1);

    std::cout << "Original: ";
    C1.print();

    std::cout << std::endl;

    int k = 2;
    CNode* joe = Josephus(C1.head, k);
    C1.head = nullptr;

    std::cout << "Josephus Problem K = " << k << std::endl;
    std::cout << joe->data;
}