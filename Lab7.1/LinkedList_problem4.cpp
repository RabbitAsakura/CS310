//Jakobe McPhail
//11/11/25
//Data Structures
#include "LinkedList.h"
#include <iostream>
using namespace std;


Node* merge(Node* head1, Node* head2)
{
    if(head1 == nullptr)
    {
        return head2;
    }

    if(head2 == nullptr)
    {
        return head1;
    }

    Node* newHead = nullptr;
    if(head1->data <= head2->data)
    {
        newHead = head1;
        newHead->next = merge(head1->next, head2);
    }
    else
    {
        newHead = head2;
        newHead->next = merge(head1, head2->next);     
    }
    return newHead;
}

/*Recursive: Time:(O(n + m)), Space:(O(n + m)), call stack will have n + m frames, one for each node
  Iterative: Time:(O(n + m)), Space: O(1), uses no new extra space
*/

int main()
{
    LinkedList L1;
    LinkedList L2;
    L1.insert(5);
    L1.insert(4);
    L1.insert(3);
    L1.insert(2);
    L1.insert(1);

    std::cout << "First List: "; 
    L1.print(); 

    L2.insert(10);
    L2.insert(20);
    L2.insert(50);
    L2.insert(70);
    L2.insert(80);
    std::cout << "Second List: "; 
    L2.print(); 

    Node* merging = merge(L1.head,L2.head);
    LinkedList mergeList;
    mergeList.head = merging;
    std::cout << "Merged: ";
    mergeList.print();   

    L1.head = nullptr;
    L2.head = nullptr;
    mergeList.head = nullptr;
}