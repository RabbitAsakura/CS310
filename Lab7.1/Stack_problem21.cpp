//Jakobe McPhail
//11/11/25
//Data Structures
#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;

bool Match(int open, char close)
{
    if (open == 1 && close == ')') return true;
    if (open == 2 && close == ']') return true;
    if (open == 3 && close == '}') return true;
    return false;
}


bool Balanced(const string& s, int index, Stack& stk)
{
    if (index == s.length())
    {
        return stk.isEmpty();
    }

    char c = s[index];

    if (c == '(')
    {
        stk.push(1); 
    }
    else if (c == '[')
    {
        stk.push(2); 
    }
    else if (c == '{')
    {
        stk.push(3); 
    }
    else if (c == ')')
    {
        if (stk.isEmpty() || !Match(stk.pop(), c))
        {
            return false; 
        }
    }
    else if (c == ']')
    {
        if (stk.isEmpty() || !Match(stk.pop(), c))
        {
            return false; 
        }
    }
    else if (c == '}')
    {
        if (stk.isEmpty() || !Match(stk.pop(), c))
        {
            return false; 
        }
    }
    return Balanced(s, index + 1, stk);
}

bool isBalanced(const string& s)
{
    Stack a;
    return Balanced(s, 0, a);
}

/*Recursive: Time:(O(n)), Space:(O(n)), call stack is n frames deep
  Iterative: Time:(O(n)), Space:(O(n)), stack grows to O(n)
*/

int main()
{
    Stack S1;
    string str1 = "{[()]}";
    std::cout << "'" << str1 << "': " << (isBalanced(str1) ? "Balanced" : "Not Balanced") << std::endl;

}