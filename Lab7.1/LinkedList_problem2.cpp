//Jakobe McPhail
//11/11/25
//Data Structures
#include "LinkedList.h"
#include <iostream>
using namespace std;

Node* findMiddleRecursive(Node* slow, Node* fast)
{
    if (fast == nullptr || fast->next == nullptr)
    {
        return slow;
    }
    return findMiddleRecursive(slow->next, fast->next->next);
}

Node* findMiddle(Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    return findMiddleRecursive(head, head);
}

/*Recursive: Time: O(n), Space: O(n), function calls upon itself
  Iterative: Time: O(n), Space: O(1), only stores two pointers
*/

int main()
{
    LinkedList L1;
    L1.insert(5);
    L1.insert(4);
    L1.insert(3);
    L1.insert(2);
    L1.insert(1);

    std::cout << "Original: "; 
    L1.print(); 
    Node* middleNode = findMiddle(L1.head); 

    if (middleNode != nullptr)
    {
        std::cout << "The middle node's data is: " << middleNode->data << std::endl;
    }
    else
    {
        std::cout << "The list is empty." << std::endl;
    }

}