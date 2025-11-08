//Jakobe McPhail
//Data Structures
#include <iostream>
#include <stdexcept>
using namespace std;

struct DDLNode
{
    int val;
    DDLNode* next;
    DDLNode* prev;
    DDLNode(int v) : val(v), next(nullptr), prev(nullptr) {}
};

void insertHead(DDLNode*& head,DDLNode*& tail, int val)
{
    DDLNode* newNode = new DDLNode(val);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertTail(DDLNode*& head, DDLNode*& tail,int val)
{
    DDLNode* newNode = new DDLNode(val);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteHead(DDLNode*& head, DDLNode*& tail)
{
    if(head == nullptr)
    {
        throw runtime_error("List is empty");
    }
    else
    {
        DDLNode* temp = head;
        head = head->next;
        if(head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
}

void deleteTail(DDLNode*& head, DDLNode*& t)
{
     if(head == nullptr)
    {
        throw runtime_error("List is empty");
    }
    else
    {
        DDLNode* temp = t;
        t = t->prev;
        if(t != nullptr)
        {
            t->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }
}

void InsertAfter(DDLNode* node, int val, DDLNode*& tail)
{
    if(node == nullptr)
    {
        throw runtime_error("Given node is null");
    }
    else
    {
        DDLNode* newNode = new DDLNode(val);
        newNode->next = node->next;
        newNode->prev = node;
        if(node->next != nullptr)
        {
            node->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        node->next = newNode;
    }
}

void deleteNode(DDLNode* node)
{
    if(node == nullptr)
    {
        throw runtime_error("Given node is null");
    }
    else
    {
        if(node->prev!= nullptr)
        {
            node->prev->next = node->next;
        }
        if(node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
        delete node;
    }
}

void reverse(DDLNode*& head, DDLNode*& tail)
{
    DDLNode* current = head;
    DDLNode* temp = nullptr;
    tail = head;

    while(current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != nullptr)
    {
        head = temp->prev;
    }
}

DDLNode* middle(DDLNode* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    DDLNode* slow = head;
    DDLNode* fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool hasCycle(DDLNode* head)
{
    if(head == nullptr)
    {
        return false;
    }
    DDLNode* slow = head;
    DDLNode* fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    DDLNode* head = nullptr;
    DDLNode* tail = nullptr;
    insertHead(head, tail, 10);
    insertHead(head, tail, 20);
    insertHead(head, tail, 30);
    insertHead(head, tail, 40);
    insertTail(head, tail, 50);
    reverse(head, tail);
    
    for(DDLNode* p = head; p; p = p->next)
    {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
}