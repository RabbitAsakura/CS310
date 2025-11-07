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

void insertHead(CLLNode*& head, int val)
{
    CLLNode* newNode = new CLLNode(val);
    if(head == nullptr)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        CLLNode* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void insertTail(CLLNode*& tail, int val)
{
    CLLNode* newNode = new CLLNode(val);
    if(tail == nullptr)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
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
        CLLNode* tail = head->next;
        head->next = tail->next;
        delete tail;
    }
}

void deleteTail(CLLNode*& tail)
{
    if(tail == nullptr)
    {
        throw runtime_error("List is empty");
    }
    else if(tail->next == tail)
    {
        delete tail;
        tail = nullptr;
    }
    else
    {
        CLLNode* current = tail->next;
        CLLNode* prev = tail;
        while(current->next != tail)
        {
            prev = current;
            current = current->next;
        }
        prev->next = tail;
        delete current;
    }
}

int josephus(CLLNode*& head, int k)
{
    if(head == nullptr || k <= 0)
    {
        throw runtime_error("Invalid input");
    }
    if(head->next == head)
    {
        int val = head->val;
        delete head;
        head = nullptr;
        return val;
    }
    CLLNode* current = head;
    CLLNode* prev = nullptr;

    while(prev->next != head)
    {
        prev = prev->next;
    }
    while(current->next != current)
    {
        for(int i = 1; i < k; i++)
        {
            prev = current;
            current = current->next;
        }
        if(current == head)
        {
            head = head->next;
        }
        prev->next = current->next;
        CLLNode* temp = current;
        current = prev->next;
        delete temp;
    }

    int survivor = head->val;
    delete head;
    head = nullptr;
    return survivor;
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

void sortedInsert(CLLNode*& head, int val)
{
    CLLNode* newNode = new CLLNode(val);
    if(head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
    }
    else if(val < head->val)
    {
        CLLNode* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
    else
    {
        CLLNode* current = head;
        while(current->next != head && current->next->val < val)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


int main()
{
    CLLNode* head = nullptr;
    CLLNode* tail = nullptr;
    sortedInsert(head, 30);
    sortedInsert(head, 40);
    sortedInsert(head, 60);
    sortedInsert(head, 10);
    for(CLLNode* p = head; p; p = p->next)
    {
        cout << p->val << " ";
        if(p->next == head) break;
    }
    cout << "\n";


    //cout << "Cycle Length: " << cycleLength(head) << "\n";

    /*auto [head1, head2] = split(head);
    std::cout << "Split: ";
    for (CLLNode* p = head1; p; p = p->next)
    {
        cout << p->val << " ";
        if (p->next == head1) break;
    }
    cout << " | ";
    for (CLLNode* p = head2; p; p = p->next)
    {
        cout << p->val << " ";
        if (p->next == head2) break;
    }
    cout << "\n";*/

    //std::cout << "Josephus: " << josephus(head, 3) << "\n";
}