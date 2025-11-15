//Jakobe McPhail
//11/11/25
//Data Structures
#include "LinkedList.h"
#include <iostream>
using namespace std;

bool hasCycleRecusrsion(Node* slow, Node* fast)
{
    if(fast == nullptr || fast->next == nullptr)
    {
        return false;
    }

    Node* s = slow->next;
    Node* f = fast->next->next;

    if(s == f)
    {
        return true;
    }

    return hasCycleRecusrsion(s,f);
}

bool hasCycle(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return false;
    }
    return hasCycleRecusrsion(head, head);
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

    Node* node = L1.head->next->next->next->next;
    Node* node2 = L1.head->next->next;
    node->next = node2;

    std::cout << "Does the list have a cycle: ";
    if(hasCycle(L1.head))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}