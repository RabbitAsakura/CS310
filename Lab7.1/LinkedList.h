//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val) , next(nullptr) {}
};

class LinkedList
{
    public:
    Node* head;
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        Node* current = head;
        while(current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    void insert(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void print()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
#endif