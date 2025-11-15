//Jakobe McPhail
//11/14/25
//Data Structures
#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

void mySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int getSize(Node* head)
{
    int size = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

void heapifyDown(int* arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        mySwap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

void buildMaxHeap(int* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyDown(arr, n, i);
    }
}

Node* heapSort(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int n = getSize(head);

    int* arr = new int[n];
    Node* temp = head;
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        mySwap(arr[0], arr[i]);

        heapifyDown(arr, i, 0);
    }

    temp = head;
    for (int i = 0; i < n; i++)
    {
        temp->data = arr[i];
        temp = temp->next;
    }

    delete[] arr;
    
    return head; 
}

/*Recursive: Time:(O(n log n)), Space:(O(n))
  Iterative: Time:(O(n log n)), Space:(O(n)) 
*/

int main()
{
    SortedLinkedList L1;
    L1.insert(5);
    L1.insert(11);
    L1.insert(9);
    L1.insert(17);
    L1.insert(44);

    std::cout << "Original: ";
    L1.print();

    L1.head = heapSort(L1.head);

    std::cout << "Updated: ";
    L1.print();
}