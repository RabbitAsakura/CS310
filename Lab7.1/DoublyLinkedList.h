//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>

struct DNode
{
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(nullptr) , prev(nullptr) {}
};

class DoublyLinkedList
{
    public: 
    DNode* head;
    DoublyLinkedList() : head(nullptr) {}
    ~DoublyLinkedList()
    {
        DNode* current = head;
        while (current != nullptr)
        {
            DNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void insert(int val)
    {
        DNode* newNode = new DNode(val);
        newNode->next = head;
        if(head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    void print()
    {
        DNode* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
#endif