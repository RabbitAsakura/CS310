//Jakobe McPhail
//11/11/25
//Data Structures
#include "LinkedList.h"
using namespace std;
#include <iostream>

void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseRecursion(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* newHead = reverseRecursion(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    LinkedList L1;
    L1.insert(1); L1.insert(2); L1.insert(3); L1.insert(4); L1.insert(5);

    cout << "Original: "; L1.print();
    L1.head = reverseRecursion(L1.head);
    cout << "Reversed: "; printList(L1.head);
}