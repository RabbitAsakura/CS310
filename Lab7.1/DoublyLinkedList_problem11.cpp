//Jakobe McPhail
//11/11/25
//Data Structures
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

struct MLNode
{
    int data;
    MLNode* next;
    MLNode* prev;
    MLNode* child; 
    MLNode(int val) : data(val), next(nullptr), prev(nullptr), child(nullptr) {}
};

void printList(MLNode* head)
{
    MLNode* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

MLNode* flatten(MLNode* head)
{
    MLNode* current = head;

    while (current != nullptr)
    {
        if (current->child == nullptr)
        {
            current = current->next;
        }
        else
        {
            MLNode* mainListNext = current->next;

            MLNode* childListHead = current->child;

            flatten(childListHead);

            MLNode* childListTail = childListHead;
            while (childListTail->next != nullptr)
            {
                childListTail = childListTail->next;
            }

            current->next = childListHead;
            childListHead->prev = current;
            current->child = nullptr; 

            childListTail->next = mainListNext;
            if (mainListNext != nullptr)
            {
                mainListNext->prev = childListTail;
            }
            current = mainListNext;
        }
    }
    return head;
}

/*Recursive: Time:(O(n)), Space:(O(n)), call stack will be n frames deep
  Iterative: Time:(O(n)), Space:(O(n)), uses a helper stack to store pointers->stack will hold n nodes
*/

int main()
{
    MLNode* n1 = new MLNode(1);
    MLNode* n2 = new MLNode(2);
    MLNode* n7 = new MLNode(7);
    
    n1->next = n2;
    n2->prev = n1;
    n2->next = n7;
    n7->prev = n2;

    MLNode* n3 = new MLNode(3);
    MLNode* n4 = new MLNode(4);
    MLNode* n6 = new MLNode(6);
    
    n3->next = n4;
    n4->prev = n3;
    n4->next = n6;
    n6->prev = n4;
    
    MLNode* n5 = new MLNode(5);
    
    n2->child = n3;
    n4->child = n5;

    std::cout << "Original list: ";
    printList(n1); 

    std::cout << std::endl;
    MLNode* head = flatten(n1);

    std::cout << "Flattened list: ";
    printList(head); 
}