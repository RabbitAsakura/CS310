//Jakobe McPhail
//11/14/25
//Data Structures
#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

Node* getTail(Node* head)
{
    while(head && head->next) head = head->next;
    return head;
}

void partition(Node* head, Node* pivot, Node** less, Node** greater)
{
    if(!head) return;
    partition(head->next, pivot, less, greater);
    if(head->data < pivot->data)
    {
        head->next = *less;
        *less = head;
    }
    else
    {
        head->next = *greater;
        *greater = head;
    }
}

Node* quickSortRec(Node* head)
{
    if(!head || !head->next) return head;

    Node* pivot = getTail(head);
    Node* less = nullptr;
    Node* greater = nullptr;

    Node* temp = head;
    while(temp->next != pivot) temp = temp->next;
    temp->next = nullptr;

    partition(head, pivot, &less, &greater);

    Node* sortedLess = quickSortRec(less);
    Node* sortedGreater = quickSortRec(greater);

    Node* newHead = sortedLess ? sortedLess : pivot;
    if(sortedLess)
    {
        getTail(sortedLess)->next = pivot;
    }
    pivot->next = sortedGreater;
    return newHead;
}


int main()
{
    SortedLinkedList L1;
    L1.insert(1);
    L1.insert(2);
    L1.insert(7);
    L1.insert(3);
    L1.insert(9);
    std::cout << "Original: ";
    L1.print();

    std::cout << std::endl;

    L1.head = quickSortRec(L1.head);
    std::cout << "After Quick Sort: ";
    L1.print();
}