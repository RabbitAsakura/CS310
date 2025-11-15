//Jakobe McPhail
//11/14/25
//Data Structures
#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

Node* sortedInsert(Node* sortedHead, Node* newNode)
{
    if (sortedHead == nullptr)
    {
        return newNode;
    }
    
    if (newNode->data <= sortedHead->data)
    {
        newNode->next = sortedHead;
        return newNode;
    }

    sortedHead->next = sortedInsert(sortedHead->next, newNode);
    
    return sortedHead;
}


Node* insertionSort(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node* nodeToInsert = head;

    Node* restOfList = head->next;

    nodeToInsert->next = nullptr;

    Node* sorted_rest = insertionSort(restOfList);

    return sortedInsert(sorted_rest, nodeToInsert);
}

/*Recursive: Time:(O(n^2)), Space:(O(n^2)), function calls itself n times
  Iterative: Time:(O(n^2)), Space:(O(1)), In-place
*/

int main()
{
    SortedLinkedList L1;
    L1.insert(60);
    L1.insert(100);
    L1.insert(9);
    L1.insert(0);
    L1.insert(10);
    std::cout << "Original: ";
    L1.print();

    L1.head = insertionSort(L1.head);
    std::cout << "Updated: ";
    L1.print();
}