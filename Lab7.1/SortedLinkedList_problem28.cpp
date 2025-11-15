//Jakobe McPhail
//11/14/25
//Data Structures
#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

Node* findMiddle(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next; 

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; 
}

Node* merge(Node* left, Node* right)
{
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* newHead = nullptr;

    if (left->data <= right->data)
    {
        newHead = left;
        newHead->next = merge(left->next, right);
    }
    else
    {
        newHead = right;
        newHead->next = merge(left, right->next);
    }
    return newHead;
}

Node* mergeSort(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node* middle = findMiddle(head);
    
    Node* right_half = middle->next;
    middle->next = nullptr; 
    Node* left_half = head;

    Node* sorted_left = mergeSort(left_half);
    Node* sorted_right = mergeSort(right_half);

    return merge(sorted_left, sorted_right);
}


int main()
{
    LinkedList L1;
    L1.insert(5);
    L1.insert(1);
    L1.insert(9);
    L1.insert(3);
    L1.insert(7);
    L1.insert(2);

    std::cout << "Original: ";
    L1.print();

    L1.head = mergeSort(L1.head);
    std::cout << std::endl;

    std::cout << "Updated: ";
    L1.print();
}