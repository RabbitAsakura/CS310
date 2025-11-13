//Jakobe McPhail
//11/11/25
//Data Structures
#include "LinkedList.h"
#include <iostream>
using namespace std;

Node* removeMatch(Node* node, int value)
{
    if(node == nullptr)
    {
        return nullptr;
    }

    if(node->data == value)
    {
        Node* nextNode = node->next;
        delete node;
        return removeMatch(nextNode, value);
    }
    else
    {
        node->next = removeMatch(node->next, value);
        return node;
    }
}

Node* removeDuplicates(Node* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    head->next = removeDuplicates(head->next);
    head->next = removeMatch(head->next, head->data);
    return head;
}


int main()
{
    LinkedList L1;
    L1.insert(5);
    L1.insert(4);
    L1.insert(3);
    L1.insert(2);
    L1.insert(1);
    L1.insert(4);
    L1.insert(2);

    std::cout << "Original: "; 
    L1.print(); 

    L1.head = removeDuplicates(L1.head);

    std::cout << "Updated: ";
    L1.print();
}