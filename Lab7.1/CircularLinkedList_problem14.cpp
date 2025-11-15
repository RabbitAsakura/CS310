//Jakobe McPhail
//11/11/25
//Data Structures
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

void SortedRecursive(CNode* current, CNode* newNode, CNode* head)
{
    if (current->data <= newNode->data && current->next->data >= newNode->data)
    {
        newNode->next = current->next;
        current->next = newNode;
        return; 
    }

    if (current->data > current->next->data && newNode->data >= current->data)
    {
        newNode->next = current->next; 
        current->next = newNode;      
        return;
    }
    
    SortedRecursive(current->next, newNode, head);
}

CNode* insertSorted(CNode* head, int val)
{
    CNode* newNode = new CNode(val);
    if (head == nullptr)
    {
        newNode->next = newNode; 
        return newNode;
    }

    if (val <= head->data)
    {
        CNode* tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        return newNode;
    }
    SortedRecursive(head, newNode, head);
    return head;
}

/*Recursive: Time:(O(n)), Space:(O(n)), call stack depth of O(n)
  Iterative: Time:(O(n)), Space:(O(1)), 
*/

int main()
{
    CircularLinkedList C1;
    C1.head = insertSorted(C1.head, 50);
    C1.head = insertSorted(C1.head, 20);
    C1.head = insertSorted(C1.head, 30);
    std::cout << "Orginal: ";
    C1.print();

    std::cout << std::endl;
    C1.head = insertSorted(C1.head, 1);
    C1.head = insertSorted(C1.head, 25);
    C1.head = insertSorted(C1.head, 51);
    std::cout << "Updated: ";
    C1.print();
}