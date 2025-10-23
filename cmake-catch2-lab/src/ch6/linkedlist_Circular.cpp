//Jakobe McPhail
//10/23/25


/*
* H -> [1] -> [2] -> [3] -> [1]
*/

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
      Node* head = nullptr;
      Node* tail = nullptr;
      int size = 0;

      public:
        ~CircularLinkedList()
        {
            if(!head) return;
            Node* current = head->next;
            while(current != head)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
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
                tail = newNode;
            }
            size++;
        }

        void InsertAtFront(T value)
        {
            Node* newNode = new Node(value);
            if(!head)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        T DeleteAtFront()
        {
            if(!head) throw std::underflow_error("List is empty");
            T value = head->data;
            if(head == tail)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            size--;
            return value;
        }

        T Delete(T value)
        {
            if(!head) throw std::underflow_error("List is empty");
            Node* current = head;
            Node* previous = nullptr;
            while(current && current->data != value)
            {
                previous = current;
                current = current->next;
            }
            if(!current) throw std::underflow_error("Value not found");
            if(current == head)
            {
                head = head->next;
            }
        }
};