#ifndef CH4E2_H
#define CH4E2_H

#include "ch4e1.h"

class sortedLinkedList : public UnsortedLinkedList
{
    public:
    sortedLinkedList() : UnsortedLinkedList() {}
    
    void Insert(ItemType* item) override
    {
        Node* newNode = new Node(item);
        Node* current = listData;
        Node* prev = nullptr;
        
        while(current != nullptr && current->item->LessThan(*item))
        {
            prev = current;
            current = current->next;
        }
        if(prev == nullptr)
        {
            newNode->next = listData;
            listData = newNode;
        }
        else
        {
           newNode->next = current;
           prev->next = newNode;
        }
    }

    void Remove(ItemType &item) override
    {

    }

    
};
#endif