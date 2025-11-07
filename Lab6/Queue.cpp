//Jakobe McPhail
//Data Structures
#include <iostream>
#include <stdexcept>
#include <stack>
using namespace std;

class Queue
{
    static const int MAX = 1000;
    int arr[MAX];
    int front, rear;

    public:
    Queue() : front(0), rear(0) {}
    bool enqueue(int x);
    int dequeue();
    int size() const;
    int getFront() const;
    bool isEmpty() const;
    bool isFull() const;
};

class StackfromQueue
{
    Queue q1, q2;
    public:
    void push(int x);
    int pop();
};

int Queue::size() const
{
    return (rear - front + MAX) % MAX;
}

bool Queue::isEmpty() const
{
    return front == rear;
}

int Queue::getFront() const
{
    if(isEmpty())
    {
        throw runtime_error("Queue is empty");
    }
    return arr[front];
}

bool Queue::isFull() const
{
    return (rear + 1) % MAX == front;
}

bool Queue::enqueue(int x)
{
    if(isFull())
    {
        return false;
    }
    arr[rear] = x;
    rear = (rear + 1) % MAX;
    return true;
}

int Queue::dequeue()
{
    if(isEmpty())
    {
        throw runtime_error("Queue underflow");
    }
    int val = arr[front];
    front = (front + 1) % MAX;
    return val;
}

void ReverseK(Queue& q, int k)
{
    if(k <= 0 || q.isEmpty())
    {
        return;
    }
    Queue s;
    for(int i = 0; i < k; i++)
    {
        s.enqueue(q.dequeue());
    }
    while(!s.isEmpty())
    {
        q.enqueue(s.dequeue());
    }
    int size = q.size();
    for(int i = 0; i < size - k; i++)
    {
        q.enqueue(q.dequeue());
    }
}

void generateBinary(int n)
{
    Queue q;
    q.enqueue(1);
    for(int i = 0; i < n; i++)
    {
        int front = q.dequeue();
        cout << front << " ";
        q.enqueue(front * 10);
        q.enqueue(front * 10 + 1);
    }
}

struct treeNode { int val; treeNode* left; treeNode* right;};
void levelOrder(treeNode* root)
{
    if(root == nullptr)
    {
        return;
    }
    Queue q;
    q.enqueue(root->val);
    while(!q.isEmpty())
    {
        treeNode*current = q.getFront();
        q.dequeue();
        cout << current->val << " ";
        if(current->left != nullptr)
        {
            q.enqueue(current->left->val);
        }
        if(current->right != nullptr)
        {
            q.enqueue(current->right->val);
        }
    }
}

void slidingWindowMax(int arr[], int n, int k, int out[])
{
    
}