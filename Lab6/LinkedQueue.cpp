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
    void display() const;
    QNode* getFrontNode() const {return front;}
};

void LinkedQueue::display() const
{
    if(isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    QNode* curr = front;
    while(curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n";
}

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
    QNode* curr1 = q1.getFrontNode();
    QNode* curr2 = q2.getFrontNode();
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
    void display() const;
    void push(int x);
    int pop();
};
void StackFromLinkedQueue::push(int x)
{
    q.enqueue(x);
    int size = 0;
    QNode* curr = q.getFrontNode();
    while(curr != nullptr)
    {
        size++;
        curr = curr->next;
    }
    for(int i = 0; i < size - 1; i++)
    {
        q.enqueue(q.dequeue());
    }
}
int StackFromLinkedQueue::pop()
{
    if(q.isEmpty())
    {
        throw runtime_error("Stack underflow");
    }
    return q.dequeue();
}
void StackFromLinkedQueue::display() const
{
    if(q.isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    LinkedQueue temp = q;
    reverse(temp);
    temp.display();
}

int middle(const LinkedQueue &q)
{
    if(q.isEmpty())
    {
        throw runtime_error("Queue is empty");
    }
    QNode* slow = q.getFrontNode();
    QNode* fast = q.getFrontNode();
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

void removeDuplicates(LinkedQueue &q)
{
    if(q.isEmpty())
    {
        return;
    }
    LinkedQueue temp;
    QNode* curr = q.getFrontNode();
    while(curr != nullptr)
    {
        int val = curr->val;
        bool found = false;
        QNode* tempCurr = temp.getFrontNode();
        while(tempCurr != nullptr)
        {
            if(tempCurr->val == val)
            {
                found = true;
                break;
            }
            tempCurr = tempCurr->next;
        }
        if(!found)
        {
            temp.enqueue(val);
        }
        curr = curr->next;
    }
    while(!q.isEmpty())
    {
        q.dequeue();
    }
    QNode* tempCurr = temp.getFrontNode();
    while(tempCurr != nullptr)
    {
        q.enqueue(tempCurr->val);
        tempCurr = tempCurr->next;
    }
}

void rotateK(LinkedQueue &q, int k)
{
    if(q.isEmpty() || k <= 0)
    {
        return;
    }
    int count = 0;
    QNode* curr = q.getFrontNode();
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