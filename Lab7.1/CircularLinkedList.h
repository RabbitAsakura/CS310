//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include <iostream>

struct CNode
{
    int data;
    CNode* next;
    CNode(int val) : data(val) , next(nullptr) {}
};

class CircularLinkedList
{
    public:
    CNode* head;
    CircularLinkedList() : head(nullptr) {}
    ~CircularLinkedList()
    {
        if (head == nullptr)
        {
            return; 
        }
        CNode* current = head->next;
        CNode* nextNode;
        while (current != head)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
        head = nullptr;
    }
    void insert(int val)
    {
        CNode* newNode = new CNode(val);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            CNode* tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }

            newNode->next = head;
            tail->next = newNode;
            head = newNode; 
        }
    }
    void print()
    {
    if (head == nullptr)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }
        CNode* temp = head;
        do
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head); 
    }
};
#endif