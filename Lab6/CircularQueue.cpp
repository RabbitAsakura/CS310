//Jakobe McPhail
//Data Structures
#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class CircularQueue
{
    static const int MAX = 100;
    int arr[MAX];
    int front, rear, size;
    public:
    CircularQueue() : front(0), rear(-1), size(0) {}
    bool enqueue(int x);
    int dequeue();
    int getFront() const;
    bool isEmpty() const;
    bool isFull() const;
};

bool CircularQueue::enqueue(int x)
{
    if(isFull())
    {
        return false;
    }
    rear = (rear + 1) % MAX;
    arr[rear] = x;
    size++;
    return true;
}

int CircularQueue::dequeue()
{
    if(isEmpty())
    {
        throw runtime_error("Queue is empty");
    }
    int x = arr[front];
    front = (front + 1) % MAX;
    size--;
    return x;
}

void firstNegative(int arr[], int n, int k)
{
    CircularQueue cq;
    for(int i = 0; i < k; i++)
    {
        if(arr[i] < 0)
        {
            cq.enqueue(arr[i]);
        }
    }
    for(int i = k; i <= n; i++)
    {
        if(!cq.isEmpty())
        {
            cout << cq.getFront() << " ";
        }
        else
        {
            cout << "0 ";
        }
        if(i < n)
        {
            if(arr[i - k] < 0)
            {
                cq.dequeue();
            }
            if(arr[i] < 0)
            {
                cq.enqueue(arr[i]);
            }
        }
    }
}

int circularTour(int petrol[], int distance[], int n)
{
    int start = 0, end = 1;
    int curr_petrol = petrol[start] - distance[start];
    while(end != start || curr_petrol < 0)
    {
        while(curr_petrol < 0 && start != end)
        {
            curr_petrol -= petrol[start] - distance[start];
            start = (start + 1) % n;
            if(start == 0)
            {
                return -1;
            }
        }
        curr_petrol += petrol[end] - distance[end];
        end = (end + 1) % n;
    }
    return start;
}

class LRU
{

};

void rotate(CircularQueue &q, int k)
{
    if(q.isEmpty() || k <= 0)
    {
        return;
    }
    for(int i = 0; i < k; i++)
    {
        int x = q.dequeue();
        q.enqueue(x);
    }
}

bool isPalindrome(const char* s)
{
    int left = 0;
    int right = strlen(s) - 1;
    while(left < right)
    {
        if(s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void printReverse(CircularQueue &q)
{
    if(q.isEmpty())
    {
        return;
    }
    int x = q.dequeue();
    printReverse(q);
    cout << x << " ";
    q.enqueue(x);
}

