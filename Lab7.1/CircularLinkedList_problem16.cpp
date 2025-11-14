//Jakobe McPhail
//11/11/25
//Data Structures
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

int countLength(CNode* current, CNode* stop)
{
    if (current->next == stop)
    {
        return 1;
    }
    return 1 + countLength(current->next, stop);
}

int getLength(CNode* head)
{
    if (head == nullptr) return 0;
    if (head->next == head) return 1;
    return countLength(head, head);
}

CNode* getNode(CNode* node, int steps)
{
    if (steps == 0)
    {
        return node;
    }
    return getNode(node->next, steps - 1);
}

CNode* split(CNode* head)
{
    int n = getLength(head);
    
    if (n < 2)
    {
        return nullptr; 
    }

    int splitIndex = (n / 2) - 1;

    CNode* tail1 = getNode(head, splitIndex);
    
    CNode* head2 = tail1->next;
    
    int list2_len = n - (n / 2);
    CNode* tail2 = getNode(head2, list2_len - 1);

    tail1->next = head;    
    tail2->next = head2;   
    return head2;
}


int main()
{
    CircularLinkedList C1;
    C1.insert(1);
    C1.insert(2);
    C1.insert(3);
    C1.insert(4);
    C1.insert(5);
    C1.insert(6);
    std::cout << "Original: ";
    C1.print();

    std::cout << std::endl;
    CircularLinkedList C2;
    C2.head = split(C1.head);
    std::cout << "First Half: ";
    C1.print();

    std::cout << std::endl;
    std::cout << "Second Half: ";
    C2.print();
}