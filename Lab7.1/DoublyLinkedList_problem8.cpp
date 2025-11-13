//Jakobe McPhail
//11/11/25
//Data Structures
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DNode* insert(DNode* head, int val)
{
    DNode* newNode = new DNode(val);
    if (head == nullptr)
    {
        return newNode;
    }

    if (val <= head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode; 
    }

    DNode* restOfList = insert(head->next, val);

    head->next = restOfList;
    if (restOfList != nullptr) // Check in case we inserted at the end
    {
        restOfList->prev = head;
    }
    return head;
}


int main()
{
    DoublyLinkedList D1;
    D1.head = insert(D1.head, 20);
    D1.head = insert(D1.head, 10);
    D1.head = insert(D1.head, 15);
    D1.head = insert(D1.head, 0);
    D1.head = insert(D1.head, 100);
    D1.head = insert(D1.head, 4);

    std::cout << "Sorted List: ";
    D1.print();

}