//Jakobe McPhail
//10/21/25
#include <iostream>


template <typename T, int Capacity>
class ArrayStack
{
    private:
        int top = -1;
        T data[Capacity];

    public:
        void push(T value)
        {
            if(top > Capacity - 1)
            {
                throw std::overflow_error("Stack overflow");
            }
            else
            {
                data[++top] = value;
            }
        }

        T pop()
        {
            if(top < 0)
            {
                throw std::underflow_error("Stack underflow");
            }
            else
            {
                return data[top--];
            }
        }

        bool isFull() const
        {
            return top == Capacity - 1;
        }

        bool isEmpty() const
        {
            return top == -1;
        }

};