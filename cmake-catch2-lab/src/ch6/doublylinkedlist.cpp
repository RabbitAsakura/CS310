#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class DoublyLinkedList
{
    private:
    struct Node 
    {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val) , next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    public:
    ~DoublyLinkedList()
    {
         while(!(isEmpty()))
         {
            removeFromFront();
         }
    }
    void InsertAtFront(T value)
    {
        Node* newNode = new Node(value);
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
        size++;
    }

    void InsertAtEnd(T value)
    {
        Node* newNode = new Node(value);
        if(!head)
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
        size++;
    }

    T RemoveAtFront()
    {
        if(!head) throw std::underflow_error("List is empty");
            T value = head->data;
            Node* temp = head;
            head = head->next;
            if(head) head->prev = nullptr;
            else tail = nullptr;

            delete temp;
            size--;
            return value;
    }

    T RemoveAtPosition(int pos)
    {
        if(pos < 0 || pos >= size) throw std::out_of_range("Position out of range");
        if(pos == 0) return RemoveAtFront();
        if(pos == size - 1) return RemoveAtEnd();

        Node* current = head;
        for(int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        T value = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
        return value;
    }

};

int main()
{
    DoublyLinkedList<int> list;
    list.InsertAtFront(20);
    list.InsertAtFront(30);

}