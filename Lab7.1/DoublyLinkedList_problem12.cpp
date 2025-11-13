//Jakobe McPhail
//11/11/25
//Data Structures
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DNode* rotateByOne(DNode* head)
{
    DNode* tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    
    DNode* newTail = tail->prev;
    
    newTail->next = nullptr; 
    tail->prev = nullptr;
    
    tail->next = head; 
    head->prev = tail;
    
    return tail; 
}

DNode* rotate(DNode* head, int k)
{
    if (head == nullptr || head->next == nullptr || k <= 0)
    {
        return head;
    }

    DNode* newHead = rotateByOne(head);
    return rotate(newHead, k - 1);
}

DNode* rotateWrapper(DNode* head, int k)
{
    if (head == nullptr || k <= 0) return head;

    int len = 0;
    DNode* temp = head;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    int actual_k = k % len;
    
    if (actual_k == 0) return head; 
    return rotate(head, actual_k);
}

int main()
{
    DoublyLinkedList D1;
    D1.insert(1);
    D1.insert(2);
    D1.insert(3);
    D1.insert(4);
    D1.insert(5);
    std::cout << "Original: ";
    D1.print();

    int k = 2;
    D1.head = rotateWrapper(D1.head, k);
    std::cout << std::endl;
    std::cout << "After rotating by 2: ";
    D1.print();
}