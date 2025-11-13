//Jakobe McPhail
//11/11/25
//Data Structures
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DNode* Delete(DNode* head, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->data == val)
    {
        DNode* newHead = head->next; 
        if (newHead != nullptr)
        {
            newHead->prev = nullptr;
        }
        delete head;
        return newHead; 
    }
    DNode* restOfList = Delete(head->next, val);
    head->next = restOfList;
    
    if (restOfList != nullptr)
    {
        restOfList->prev = head; 
    }
    
    return head;
}


int main()
{
    DoublyLinkedList D1;
    D1.insert(5);
    D1.insert(6);
    D1.insert(7);
    D1.insert(8);
    D1.insert(9);
    D1.insert(10);

    std::cout << "Original: ";
    D1.print();

    std::cout << std::endl;

    D1.head = Delete(D1.head, 8);
    D1.head = Delete(D1.head, 10);

    std::cout << "After deleting two elements: ";
    D1.print();

}