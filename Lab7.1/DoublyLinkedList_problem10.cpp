//Jakobe McPhail
//11/11/25
//Data Structures
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;


DNode* insert(DNode* head, int val)
{
    DNode* newNode = new DNode(val);
    if (head == nullptr) return newNode;
    if (val <= head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    DNode* rest = insert(head->next, val);
    head->next = rest;
    if (rest) rest->prev = head;
    return head;
}

bool findPair(DNode* left, DNode* right, int target)
{
    if (left == nullptr || right == nullptr || left == right || right->next == left)
    {
        return false;
    }

    int currentSum = left->data + right->data;

    if (currentSum == target)
    {
        return true;
    }
    if (currentSum < target)
    {
        return findPair(left->next, right, target);
    }
    else
    {
        return findPair(left, right->prev, target);
    }
}

bool findPairSum(DNode* head, int target)
{
    if (head == nullptr)
    {
        return false;
    }

    DNode* tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    return findPair(head, tail, target);
}


/*Recursive: Time:(O(n)), Space:(O(n)), call stack grows as the pointers converge
  Iterative: Time:(O(n)), Space:(O(1)), only stores two pointers
*/

int main()
{
    DoublyLinkedList D1;
    D1.head = insert(D1.head, 20);
    D1.head = insert(D1.head, 10);
    D1.head = insert(D1.head, 15);
    D1.head = insert(D1.head, 10);
    D1.head = insert(D1.head, 100);
    D1.head = insert(D1.head, 5);


    std::cout << "Original: ";
    D1.print();

    std::cout << std::endl;
    int target = 15;
    std::cout << "Find Pair for " << target << ": ";
    std::cout << (findPairSum(D1.head, target) ? "Found" : "Not Found") << std::endl;

    int target2 = 20;
    std::cout << "Find Pair for " << target2 << ": ";
    std::cout << (findPairSum(D1.head, target2) ? "Found" : "Not Found") << std::endl;

    int target3 = 100;
    std::cout << "Find Pair for " << target3 << ": ";
    std::cout << (findPairSum(D1.head, target3) ? "Found" : "Not Found") << std::endl;

}