//Jakobe McPhail
//Data Structures
//11/9/25
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    private:
        T* arr;
        int capacity;
        int topIndex;
    public:
        Stack() : capacity(100), topIndex(-1) {arr = new T[capacity];}
        ~Stack() {delete[] arr;}
        void push(T item)
        {
            if(topIndex + 1 >= capacity)
            {
                throw std::runtime_error("Stack overflow");
            }
            arr[++topIndex] = item;
        }

        T pop()
        {
            if(isEmpty())
            {
                throw std::runtime_error("Stack underflow");
            }
            return arr[topIndex--];
        }
        T top() const
        {
            if(isEmpty())
            {
                throw std::runtime_error("Stack is empty");
            }
            return arr[topIndex];
        }
        bool isEmpty() const {return topIndex == -1;}
        bool isFull() const {return topIndex + 1 == capacity;}
        int size() const {return topIndex + 1;}
};

template <typename T>
class CircularLinkedStack
{
    private:
    struct Node
    {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* topNode;
    int count;
    public:
    CircularLinkedStack() : topNode(nullptr), count(0) {}
    ~CircularLinkedStack()
    {
        while(!isEmpty())
        {
            pop();
        }
    }
    void push(T item)
    {
        Node* newNode = new Node(item);
        if(isEmpty())
        {
            newNode->next = newNode;
            topNode = newNode;
        }
        else
        {
            newNode->next = topNode->next;
            topNode->next = newNode;
            //topNode = newNode;
        }
         count++;
    }
    T pop()
    {
        if(isEmpty())
        {
            throw std::runtime_error("Stack underflow");
        }
        Node* temp = topNode->next;
        T item = temp->data;
        if(topNode == temp)
        {
            topNode = nullptr;
        }
        else
        {
            topNode->next = temp->next;
        }
        delete temp;
        count--;
        return item;
    }

    T top() const
    {
        if(isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->next->data;
    }
    bool isEmpty() const {return count == 0;}
    int size() const {return count;}
};

template <typename T>
class Queue
{
    private:
      T* arr;
      int capacity;
      int frontIndex, rearIndex;
      int count;
    public:
       Queue() : capacity(100), frontIndex(0), rearIndex(-1), count(0)
       {
              arr = new T[capacity];
       }
    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(T item)
    {
        if(isFull())
        {
            throw std::runtime_error("Queue overflow");
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        count++;
    }

    T dequeue()
    {
        if(isEmpty())
        {
            throw std::runtime_error("Queue underflow");
        }
        frontIndex = (frontIndex) % capacity;
        T item = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return item;
    }

    T front() const
    {
        if(isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return arr[frontIndex];
    }
    bool isEmpty() const {return count == 0;}
    bool isFull() const {return count == capacity;}
    int size() const {return count;}
};

template<typename T>
class CircularLinkedQueue
{
    private:
    struct Node
    {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };  
    Node* rear;
    int count;
    public:
    CircularLinkedQueue() : rear(nullptr), count(0) {}
    ~CircularLinkedQueue()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }
    void enqueue(T item)
    {
        Node* newNode = new Node(item);
        if(isEmpty())
        {
            newNode->next = newNode;
            rear = newNode;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    T dequeue()
    {
        if(isEmpty())
        {
            throw std::runtime_error("Queue underflow");
        }
        else
        {
            Node* frontNode = rear->next;
            T item = frontNode->data;
            if(rear == frontNode)
            {
                rear = nullptr;
            }
            else
            {
                rear->next = frontNode->next;
            }
            delete frontNode;
            count--;
            return item;
        }
    }

    T front() const
    {
        if(isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return rear->next->data;
    }
    bool isEmpty() const {return count == 0;}
    int size() const {return count;}
};

template <typename T>
class CircularLinkedList
{
    private:
     struct Node
     {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
     };
     Node* head;
     int count;
     public:
      CircularLinkedList() : head(nullptr), count(0) {}
      bool isEmpty() const {return count == 0;}
      int size() const {return count;}
      ~CircularLinkedList()
      {
        while(!isEmpty())
        {
            deleteFront();
        }
      }
      void insertFront(T item)
      {
        Node* newNode = new Node(item);
        if(isEmpty())
        {
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
        }
        count++;
      }

    void insertRear(T item)
    {
        Node* newNode = new Node(item);
        if(isEmpty())
        {
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
        count++;
    }

    void deleteFront()
    {
        if(isEmpty())
        {
            throw std::runtime_error("List is empty");
        }
        Node* temp = head;
        if(head->next == head)
        {
            head = nullptr;
        }
        else
        {
            Node* tail = head;
            while(tail->next != head)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
        }
        delete temp;
        count--;
    }

    void deleteRear()
    {
        if(isEmpty())
        {
            throw std::runtime_error("List is empty");
        }
        if(head->next == head)
        {
            delete head;
            head = nullptr;
            count--;
            return;
        }
        Node* tail = head;
        Node* prev = nullptr;
        while(tail->next != head)
        {
            prev = tail;
            tail = tail->next;
        }
        prev->next = head;
        delete tail;
        count--;
    }

    void display() const
    {
        if(isEmpty())
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* current = head;
        do
        {
            std::cout << current->data << " ";
            current = current->next;
        } while(current != head);
        std::cout << std::endl;
    }
};

template<typename T>
class TextEditorBuffer
{
    private:
     CircularLinkedStack<T> buffer;
     CircularLinkedQueue<T> redoQueue;
    public:
        void type(T item)
        {
            buffer.push(item);
            redoQueue = CircularLinkedQueue<T>();
        }
        void undo()
        {
            if(buffer.isEmpty())
            {
                throw std::runtime_error("Nothing to undo");
            }
                T item = buffer.pop();
                redoQueue.enqueue(item);
        }
        void redo()
        {
            if(!redoQueue.isEmpty())
            {
                T item = redoQueue.dequeue();
                buffer.push(item);
            }
            else
            {
                throw std::runtime_error("Nothing to redo");
            }
        }
        void displayBuffer()
            {
    if(buffer.isEmpty())
    {
        std::cout << "Buffer is empty" << std::endl;
        return;
    }

    CircularLinkedStack<T> reverseStack;
    CircularLinkedStack<T> restoreStack; 

    while(!buffer.isEmpty())
    {
        T item = buffer.pop();
        reverseStack.push(item);
        restoreStack.push(item);
    }
    while(!reverseStack.isEmpty())
    {
        std::cout << reverseStack.pop();
    }
    std::cout << std::endl;
    while(!restoreStack.isEmpty())
    {
        buffer.push(restoreStack.pop());
    }
}
};

int main()
{
    Stack<int> s;
    s.push(10); s.push(20); s.push(30); s.push(40); s.push(50);
    std::cout << "Top element: " << s.top() << std::endl;
    std::cout << "Stack size: " << s.size() << std::endl;
    s.pop(); s.pop(); s.pop();
    std::cout << "Top element after popping 3 elements: " << s.top() << std::endl;
    std::cout << "Stack size after popping 3 elements: " << s.size() << std::endl;
    
    std::cout << std::endl;

    Queue<std::string> q;
    q.enqueue("A"); q.enqueue("B"); q.enqueue("C"); q.enqueue("D"); q.enqueue("E");
    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Queue size: " << q.size() << std::endl;
    q.dequeue(); q.dequeue(); q.dequeue();
    std::cout << "Front element after dequeuing 3 elements: " << q.front() << std::endl;
    std::cout << "Queue size after dequeueing 3 elements: " << q.size() << std::endl;
    q.dequeue(); q.dequeue();
    std::cout << "After dequeueing all elements: " << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << std::endl;

    std::cout << std::endl;

    CircularLinkedList<int> cll;
    cll.insertFront(1); cll.insertFront(2); cll.insertFront(0); cll.insertRear(4); cll.insertRear(6);
    std::cout << "Circular Linked List: "; cll.display();
    cll.deleteFront(); cll.deleteRear();
    std::cout << "Circular Linked List after deleting two items: "; cll.display();
    cll.deleteFront(); cll.deleteRear(); cll.deleteRear();
    std::cout << "After deleting all elements: "; cll.display();
    std::cout << std::endl;
    
    TextEditorBuffer<char> editor;
    TextEditorBuffer<std::string> editorStr;
    editor.type('P'); editor.type('e'); editor.type('t'); editor.type('e'); editor.type('r'); editor.type(' '); editor.type('P'); editor.type('a'); editor.type('n');
    std::cout << "Current buffer: "; editor.displayBuffer();
    editorStr.type("Hello World!");
    std::cout << "Current buffer(string): "; editorStr.displayBuffer();
    editor.undo(); editor.undo(); editor.undo();
    std::cout << "After undoing 3 characters: "; editor.displayBuffer();
    editor.redo(); editor.redo();
    std::cout << "After redoing 2 characters: "; editor.displayBuffer();
}