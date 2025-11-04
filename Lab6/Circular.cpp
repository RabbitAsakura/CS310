//Jakobe McPhail
//Data Structures
#include <iostream>
#include <stdexcept>
using namespace std;

struct CLLNode
{
    int val;
    CLLNode* next;
    CLLNode(int v) : val(v), next(nullptr) {}
};

void insertTail(CLLNode*& head, int val)
{
    CLLNode* newNode = new CLLNode(val);
    if(head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        CLLNode* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }
}

void deleteHead(CLLNode*& head)
{
    if(head == nullptr)
    {
        throw runtime_error("List is empty");
    }
    else if(head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        CLLNode* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        CLLNode* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
}

void deleteTail(CLLNode*& head)
{
    if(head == nullptr)
    {
        throw runtime_error("List is empty");
    }
    else if(head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        CLLNode* current = head;
        CLLNode* prev = nullptr;
        while(current->next != head)
        {
            prev = current;
            current = current->next;
        }
        prev->next = head;
        delete current;
    }
}

int josephus(CLLNode* head, int k)
{
    if(head == nullptr || k <= 0)
    {
        throw runtime_error("Invalid input");
    }
    CLLNode* current = head;
    CLLNode* prev = nullptr;
    while(current->next != current)
    {
        for(int i = 1; i < k; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
        current = prev->next;
    }
    return current->val;
}

pair<CLLNode*, CLLNode*> split(CLLNode* head)
{
    if(head == nullptr)
    {
        return {nullptr,nullptr};
    }
    CLLNode* slow = head;
    CLLNode* fast = head;
    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    CLLNode* head1 = head;
    CLLNode* head2 = slow->next;
    slow->next = head1;
    CLLNode* tail = head2;
    while(tail->next!=head)
    {
        tail = tail->next;
    }
    tail->next = head2;
    return {head1, head2};
}

int cycleLength(CLLNode* head)
{
    if(head == nullptr)
    {
        return 0;
    }
    int length = 1;
    CLLNode* current = head->next;
    while(current != head)
    {
        length++;
        current = current->next;
    }
    return length;
}