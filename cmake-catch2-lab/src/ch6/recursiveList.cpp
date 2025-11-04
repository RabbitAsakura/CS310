template<typename T>

class LinkedList
{
    private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head;
    int size;
    public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    ~LinkedList()
    {
        Node *current = head;
        while(current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    void Insert(T item)
    {

    }

    void printList()
    {
        printListHelper(head);
    }

    void printListHelper(Node *current)
    {
        if(current == nullptr)
        {
            return;
        }
        std::cout << current->data << " ";
        printListHelper(current->next);
    }
};