
#define USE_stack_queue // Uncomment to use stack_queue

#ifndef USE_stack_queue

    #include <iostream>
    #include <string>
    #include <stack>

char Biection(char c)
{
    if (c=='(') return ')';
    if (c=='{') return '{';
    if (c=='[') return ']';
    return 0;
}

int checkCorrectBrackets(std::string s)
{
    std::stack<char> t;
    for (std::size_t i=0;i<s.size();i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') t.push(s[i]);
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            if (!t.empty() && s[i] == Biection(t.top())) t.pop();
            else return 0;
    }
    if (!t.empty()) return 0;
    return 1;
}

int main()
{
    std::string s = "5*(8+3)-2/(6-4+(-2-6))";
    std::cout << "Expression with correct brackets: " << s << std::endl;
    std::cout << "Is it correct? " << checkCorrectBrackets(s) << std::endl;
}

#else

#include <iostream>
#include <string>
#include "mStack.h"

char Biection(char c)
{
    if (c=='(') return ')';
    if (c=='{') return '{';
    if (c=='[') return ']';
    return 0;
}

int checkCorrectBrackets(std::string s)
{
    mStack<char> t;
    for (std::size_t i=0;i<s.size();i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') t.push(s[i]);
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            if (!t.isEmpty() && s[i] == Biection(t.top())) t.pop();
            else return 0;
    }
    if (!t.isEmpty()) return 0;
    return 1;
}

int main()
{
    std::string s = "5*(8+3)-2/(6-4+(-2-6))";
    std::string s1 = "())";
    std::cout << "Expression with correct brackets: " << s1 << std::endl;
    std::cout << "Is it correct? " << checkCorrectBrackets(s1) << std::endl;
}

#endif
