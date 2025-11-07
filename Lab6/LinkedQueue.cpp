//Jakobe McPhail
//Data Structures
#include <iostream>
#include <stdexcept>
using namespace std;

struct QNode
{
    int val;
    QNode* next;
    QNode(int v) : val(v) , next(nullptr) {}
};

class LinkedQueue
{
    QNode* front, *rear;
    public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}
    void enqueue(int x);
    int dequeue();
    int getFront() const;
    bool isEmpty() const;
};

void LinkedQueue::enqueue(int x)
{
    QNode* newNode = new QNode(x);
    if(isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int LinkedQueue::dequeue()
{
    if(isEmpty())
    {
        throw runtime_error("Queue is empty");
    }
    int x = front->val;
    QNode* temp = front;
    front = front->next;
    delete temp;
    if(front == nullptr)
    {
        rear = nullptr;
    }
    return x;
}

bool LinkedQueue::isEmpty() const
{
    return front == nullptr;
}

int LinkedQueue::getFront() const
{
    if (isEmpty())
    {
        throw runtime_error("Queue is empty");
    }
    return front->val;
}

void reverse(LinkedQueue &q)
{
    if(q.isEmpty())
    {
        return;
    }
    int x = q.dequeue();
    reverse(q);
    q.enqueue(x);
}

LinkedQueue merge(const LinkedQueue &q1, const LinkedQueue &q2)
{
    LinkedQueue result;
    QNode* curr1 = q1.getFront();
    QNode* curr2 = q2.getFront();
    while(curr1 != nullptr && curr2 != nullptr)
    {
        if(curr1->val < curr2->val)
        {
            result.enqueue(curr1->val);
            curr1 = curr1->next;
        }
        else
        {
            result.enqueue(curr2->val);
            curr2 = curr2->next;
        }
    }
    while(curr1 != nullptr)
    {
        result.enqueue(curr1->val);
        curr1 = curr1->next;
    }
    while(curr2 != nullptr)
    {
        result.enqueue(curr2->val);
        curr2 = curr2->next;
    }
    return result;
}

class StackFromLinkedQueue
{
    LinkedQueue q;
    public:
    void push(int x);
    int pop();
};

int middle(const LinkedQueue &q)
{
    if(q.isEmpty())
    {
        throw runtime_error("Queue is empty");
    }
    QNode* slow = q.getFront();
    QNode* fast = q.getFront();
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

void rotateK(LinkedQueue &q, int k)
{
    if(q.isEmpty() || k <= 0)
    {
        return;
    }
    int count = 0;
    QNode* curr = q.getFront();
    while(curr != nullptr)
    {
        count++;
        curr = curr->next;
    }
    k = k % count;
    for(int i = 0; i < k; i++)
    {
        int x = q.dequeue();
        q.enqueue(x);
    }
}

int main()
{
    
}