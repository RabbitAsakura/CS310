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
            s.push(arr[i]);
        }
        s.push(arr[i]);
        out[i] = s.isEmpty() ? -1 : s.peek();
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
    while(!s.isEmpty())
    {
        tempStack.push(s.pop());
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
