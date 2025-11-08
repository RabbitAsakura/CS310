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
    void display() const;
    int getFront() const;
    bool isEmpty() const;
    bool isFull() const;
};

class StackfromQueue
{
    Queue q1, q2;
    public:
    void push(int x);
    bool isEmpty() const;
    void display() const;
    int pop();
};

void StackfromQueue::display() const
{
    if(q1.isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    Queue temp = q1;
    stack<int> s;
    while(!temp.isEmpty())
    {
        s.push(temp.dequeue());
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
bool StackfromQueue::isEmpty() const
{
    return q1.isEmpty();
}
int StackfromQueue::pop()
{
    if(q1.isEmpty())
    {
        throw runtime_error("Stack underflow");
    }
    return q1.dequeue();
}
void StackfromQueue::push(int x)
{
    q2.enqueue(x);
    while(!q1.isEmpty())
    {
        q2.enqueue(q1.dequeue());
    }
    swap(q1, q2);
}
void Queue::display() const
{
    if(isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    for(int i = 0; i < size(); i++)
    {
        cout << arr[(front + i) % MAX] << " ";
    }
    cout << "\n";
}

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
    if(k <= 0 || q.isEmpty() || k > q.size())
    {
        return;
    }
    StackfromQueue s;
    for(int i = 0; i < k; i++)
    {
        s.push(q.dequeue());
    }
    while(!s.isEmpty())
    {
        q.enqueue(s.pop());
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

//struct treeNode { int val; treeNode* left; treeNode* right;};
//void levelOrder() //Could not get this function to work 

void slidingWindowMax(int arr[], int n, int k, int out[])
{
    if(k <= 0 || k > n)
    {
        return;
    }
    Queue q;
    int outIndex = 0;
    for(int i = 0; i < k; i++)
    {
        while(!q.isEmpty() && arr[i] >= arr[q.getFront()])
        {
            q.dequeue();
        }
        q.enqueue(i);
    }
    for(int i = k; i < n; i++)
    {
        out[outIndex++] = arr[q.getFront()];
        while(!q.isEmpty() && q.getFront() <= i - k)
        {
            q.dequeue();
        }
        while(!q.isEmpty() && arr[i] >= arr[q.getFront()])
        {
            q.dequeue();
        }
        q.enqueue(i);
    }

    if(!q.isEmpty())
    {
        out[outIndex++] = arr[q.getFront()];
    }
    
}

void interleave(Queue& q)
{
   int size = q.size();
    if (size <= 1)
    {
        return;
    }

    int half = size / 2;
    StackfromQueue s;
    for (int i = 0; i < half; i++)
    {
        s.push(q.dequeue());
    }
    while (!s.isEmpty())
    {
        q.enqueue(s.pop());
    }
    for (int i = 0; i < size - half; i++)
    {
        q.enqueue(q.dequeue());
    }
    for (int i = 0; i < half; i++)
    {
        s.push(q.dequeue());
    }
    while (!s.isEmpty())
    {
        q.enqueue(s.pop());
        q.enqueue(q.dequeue());
    }
    if (size % 2 != 0)
    {
        q.enqueue(q.dequeue());
    }
}