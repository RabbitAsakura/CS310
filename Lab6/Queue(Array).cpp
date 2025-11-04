//Jakobe McPhail
//Data Structures
#include <iostream>
#include <stdexcept>
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
    for(int i = 0; i < k && !q.isEmpty(); i++)
    {
        s.enqueue(q.dequeue());
    }
    while(!s.isEmpty())
    {
        q.enqueue(s.dequeue());
    }
    int size = (q.rear - q.front + arr[MAX]) % MAX;
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
        int current = q.dequeue();
        cout << current << " ";
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