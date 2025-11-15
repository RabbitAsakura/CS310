//Jakobe McPhail
//11/11/25
//Data Structures
#include "Stack.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

const int ADD = -1;
const int SUB = -2;
const int MUL = -3;
const int DIV = -4;

int Operation(int op1, int op2, int op)
{
    switch (op)
    {
        case ADD: return op1 + op2;
        case SUB: return op1 - op2;
        case MUL: return op1 * op2;
        case DIV: return op1 / op2;
        default:  throw runtime_error("Invalid operator");
    }
}

int evaluate(Stack& s)
{
    int op = s.pop();
    if(op >= 0)
    {
        return op;
    }
    else
    {
        int op1 = evaluate(s);
        int op2 = evaluate(s);
        return Operation(op2, op1, op);
    }
}

int main()
{
    Stack s1;
    s1.push(7);
    s1.push(SUB);
    s1.push(5);
    s1.push(6);
    s1.push(ADD);
    int result1 = evaluate(s1);
    std::cout << "Result: " << result1 << std::endl;
}