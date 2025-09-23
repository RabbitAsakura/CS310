#define CH4E2_H
#ifndef CH4E2_H
#include "ch4e1.h"

class sortedLinkedList : public UnsortedLinkedList
{
    public:
    SortedLinkedList() : UnsortedLinkedList() {}
    
    void Insert(ItemType* item) override
    {
        Node* newNode = new Node(item);
        Node* current = listData;
        Node* previous = nullptr;
        
        while(current != nullptr && current->item->LessThan(*item))
        {
            prev = current;
            current = current->next;
        }
    }
};


#endif