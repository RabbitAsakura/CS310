//Jakobe McPhail
//11/14/25
//Data Structures
#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

int countNodes(Node* head)
{
    if(!head) return 0;
    return 1 + countNodes(head->next);
}

Node* getNodeAt(Node* head, int index)
{
    if(index == 0) return head;
    return getNodeAt(head->next, index - 1);
}

bool BinarySearchRecursive(Node* head, int target)
{
    if(!head) return false;

    int size = countNodes(head);
    if(size == 0) return false;
    int midIdx = size / 2;
    Node* mid = getNodeAt(head, midIdx);

    if(mid->data == target) return true;
    if(target < mid->data)
    {
        Node* leftEnd = getNodeAt(head, midIdx - 1);
        Node* savedNext = (leftEnd ? leftEnd->next : nullptr);
        if(leftEnd) leftEnd->next = nullptr;
        bool found = BinarySearchRecursive(head, target);
        if(leftEnd) leftEnd->next = savedNext;
        return found;
    }
        else
        {
            return BinarySearchRecursive(mid->next, target);
        }
}

Node* findMid(Node* head)
{
    if(!head) return nullptr;
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*Recursive: Time:(O(n log n)), Space:(O(log^2 n)), log n levels * O(log n) to count
  Iterative: Time:(O(n)), Space:(O(1)), Because mid finding is O(n) per level
  Real World: Recursive: Never Used, Iterative: Always used, Linked list defeats the purpose of binary search
*/

int main()
{
    SortedLinkedList L1;
    L1.insertSorted(1);
    L1.insertSorted(3);
    L1.insertSorted(5);
    L1.insertSorted(7);
    L1.insertSorted(9);
    L1.insertSorted(11);
    L1.insertSorted(13);

    cout << "Original list: ";
    L1.print();

    int target1 = 9;

    cout << "Searching for " << target1 << ": ";
    bool found1 = BinarySearchRecursive(L1.head, target1);
    cout << (found1 ? "Found" : "Not Found") << endl;
}