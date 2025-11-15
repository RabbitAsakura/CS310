//Jakobe McPhail
//11/11/25
//Data Structures
#include "LinkedList.h"
#include <iostream>
using namespace std;

Node* partition(Node* head, int x)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node* partitioned_rest = partition(head->next, x);
    if(head->data < x)
    {
        head->next = partitioned_rest;
        return head;
    }
    else
    {
        Node* temp = partitioned_rest;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data < x)
        {
            prev = temp;
            temp = temp->next;
        }
        if(prev == nullptr)
        {
            head->next = partitioned_rest;
            return head;
        }
        else
        {
            prev->next = head;
            head->next = temp;
            return partitioned_rest;
        }
    }
}

/* Recursive: Time:(O(n)), Space:(O(n)), recurses on head->next->inserts head->finding would take O(n) time
   Iterative: Time:(O(n)), Space:(O(1)), pass O(n) time 
*/

int main()
{
    LinkedList L1;
    L1.insert(1);
    L1.insert(2);
    L1.insert(3);
    L1.insert(20);
    L1.insert(5);
    L1.insert(8);
    L1.insert(10);

    std::cout << "Original: "; 
    L1.print();

    int pivot = 3;
    std::cout << "Partitioning: " << pivot << std::endl;
    L1.head = partition(L1.head, pivot);

    std::cout << "Partitioned: ";
    L1.print();
}