//Jakobe McPhail
//Data Structures
#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
    static const int MAX = 100;
    int arr[MAX];
    int top;
    public:
    Stack() : top(-1) {}
    bool push(int x);
    int pop();
    void display() const;
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
};


class minStack
{
    Stack s;
    Stack minS;
    public:
    void push(int x);
    int pop();
    int getMin() const;

};

void minStack::push(int x)
{
    s.push(x);
    if(minS.isEmpty() || x <= minS.peek())
    {
        minS.push(x);
    }
}

int minStack::pop()
{
    int val = s.pop();
    if(val == minS.peek())
    {
        minS.pop();
    }
    return val;
}

int minStack::getMin() const
{
    if(minS.isEmpty())
    {
        throw runtime_error("Stack is empty");
    }
    return minS.peek();
}

void Stack::display() const
{
    for(int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

bool Stack::isFull() const
{
    return top == MAX - 1;
}

int Stack::peek() const
{
    if(isEmpty())
    {
        throw runtime_error("Stack is empty");
    }
    return arr[top];
}
bool Stack::isEmpty() const
{
    return top == -1;
}

bool Stack::push(int x)
{
    if(isFull())
    {
        return false;
    }
    arr[++top] = x;
    return true;
}

int Stack::pop()
{
    if(isEmpty())
    {
        throw runtime_error("Stack underflow");
    }
    return arr[top--];
}

void nextGreater(int arr[], int n, int out[])
{
    Stack s;
    for(int i = n - 1; i >= 0; i--)
    {
        while(!s.isEmpty() && s.peek() <= arr[i])
        {
            s.pop();
        }
        out[i] = s.isEmpty() ? -1 : s.peek();
        s.push(arr[i]);
    }
}

bool balanced(const char* s)
{
    Stack s1;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            s1.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(s1.isEmpty())
            {
                return false;
            }
            char top = s1.pop();
            if((s[i] == ')' && top != '(') ||
               (s[i] == '}' && top != '{') ||
               (s[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s1.isEmpty();
}

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix)
{
    Stack s;
    int j = 0;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        char token = infix[i];
        if((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') || (token >= '0' && token <= '9'))
        {
            postfix[j++] = token;
        }
        else if(token == '(')
        {
            s.push(token);
        }
        else if(token == ')')
        {
            while(!s.isEmpty() && s.peek() != '(')
            {
                postfix[j++] = s.pop();
            }
            s.pop(); 
        }
        else
        {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(token))
            {
                postfix[j++] = s.pop();
            }
            s.push(token);
        }
    }
    while(!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
}

int evalPostfix(const char* postfix)
{
    Stack s;
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        char token = postfix[i];
        if(token >= '0' && token <= '9')
        {
            s.push(token - '0');
        }
        else
        {
            int val2 = s.pop();
            int val1 = s.pop();
            switch(token)
            {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

void sortStack(Stack& s)
{
    Stack tempStack;
    while(!s.isEmpty())
    {
        int temp = s.pop();
        while(!tempStack.isEmpty() && tempStack.peek() > temp)
        {
            s.push(tempStack.pop());
        }
        tempStack.push(temp);
    }
    while(!tempStack.isEmpty())
    {
        s.push(tempStack.pop());
    }
}

void stockspan(int price[], int n, int span[])
{
    Stack s;
    for(int i = 0; i < n; i++)
    {
        while(!s.isEmpty() && price[s.peek()] <= price[i])
        {
            s.pop();
        }
        span[i] = s.isEmpty() ? (i + 1) : (i - s.peek());
        s.push(i);
    }
}

int main()
{
    Stack s;
    minStack ms;
    /*ms.push(10);
    ms.push(20);
    ms.push(5);
    ms.push(15);
    cout << "Minimum element: " << ms.getMin() << "\n";*/
    /*int prices[5] = {100, 80, 70 , 60 ,50};
    int span[5];
    stockspan(prices, 5, span);
    for(int i = 0; i < 5; i++)
    {
        cout << span[i] << " ";
    }
    cout << "\n";*/
    
    //balanced("{[()]}") ? cout << "Balanced\n" : cout << "Not Balanced\n";
    const char* infix = "A+B*(C-D)/E";
    char postfix[100];
    infixToPostfix(infix, postfix);
    cout << "Infix expression: " << infix << "\n";
    cout << "Postfix expression: " << postfix << "\n";
    /*s.push(100);
    s.push(20);
    s.push(45);
    s.push(1);
    s.push(78);
    sortStack(s);
    s.display();*/
    //std::cout << "Postfix Evaluation: " << evalPostfix("231*+9-") << "\n";
    //s.push(10);
    //s.push(20);
    //s.display();
    /*int arr[6] = {4,5,2,1,7,8};
    int out[6];
    nextGreater(arr, 6, out);
    std::cout << "Next Greater Elements: ";
    for(int i = 0; i < 6; i++)
    {
        std::cout << out[i] << " ";
    }
    std::cout << "\n";*/
}