//Jakobe McPhail
//11/11/25
//Data Structures
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DNode* reverse(DNode* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    DNode* originalNext = node->next;
    node->next = node->prev;
    node->prev = originalNext;
    if (originalNext == nullptr)
    {
        return node;
    }
    return reverse(originalNext);
}

/*Recursive: Time:(O(n)), Space:(O(n)), recursion creates one stack frame for each node
  Iterative: Time:(O(n)), Space:(O(1)), swap is in-place
*/

int main()
{
    DoublyLinkedList D1;
    D1.insert(5);
    D1.insert(6);
    D1.insert(7);
    D1.insert(8);
    D1.insert(9);
    D1.insert(10);

    std::cout << "Original: ";
    D1.print();

    std::cout << std::endl;
    D1.head = reverse(D1.head);
    std::cout << "Reverse: ";
    D1.print();

}