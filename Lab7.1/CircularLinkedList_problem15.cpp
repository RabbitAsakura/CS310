//Jakobe McPhail
//11/11/25
//Data Structures
#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

void deleteNode(CNode* nodeToDelete)
{
    if (nodeToDelete == nullptr)
    {
        return;
    }

    CNode* temp = nodeToDelete->next;
    nodeToDelete->data = temp->data;
    nodeToDelete->next = temp->next;
    delete temp;
}


int main()
{
    CircularLinkedList C1;
    C1.insert(1);
    C1.insert(2);
    C1.insert(3);
    C1.insert(4);
    C1.insert(5);

    std::cout << "Original: ";
    C1.print();

    CNode* node3 = C1.head->next->next;
    deleteNode(node3);

    std::cout << std::endl;
    std::cout << "After Deleting the 3rd Node: ";
    C1.print();
}