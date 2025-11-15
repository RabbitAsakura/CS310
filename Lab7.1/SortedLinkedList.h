//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "LinkedList.h"
#include <iostream>


class SortedLinkedList : public LinkedList
{
    public:
        SortedLinkedList() : LinkedList() {}
        void insertSorted(int val)
        {
            Node* newNode = new Node(val);

        if (head == nullptr || head->data >= val)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data < val)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        }
};
#endif