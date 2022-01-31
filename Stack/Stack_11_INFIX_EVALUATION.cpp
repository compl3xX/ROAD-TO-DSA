#include <bits/stdc++.h>

using namespace std;
//Doing the operation 
int operation(int v1, int v2, char optr)
{
    if (optr == '+')
    {
        return v1 + v2;
    }
    else if (optr == '-')
    {
        return v1 - v2;
    }
    else if (optr == '*')
    {
        return v1 * v2;
    }
    else
    {
        return v1 / v2;
    }
}
//Doing the precedence of operator
int precedence(char optr)
{
    if (optr == '+' || optr == '-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
void solve(string str)
{
    stack<int> oprnds;
    stack<char> opertr;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(')
        {
            opertr.push(ch);
        }
        else if (isdigit(ch))
        {
            oprnds.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (opertr.size() > 0 && opertr.top() != '(' && precedence(ch) <= precedence(opertr.top()))
            {
                char optr = opertr.top();
                opertr.pop();
                int v2 = oprnds.top();
                oprnds.pop();
                int v1 = oprnds.top();
                oprnds.pop();

                int val = operation(v1, v2, optr);
                oprnds.push(val);
            }
            opertr.push(ch);
        }
        else if (ch == ')')
        {
            while (opertr.top() != '(')
            {
                char optr = opertr.top();
                opertr.pop();
                int v2 = oprnds.top();
                oprnds.pop();
                int v1 = oprnds.top();
                oprnds.pop();

                int val = operation(v1, v2, optr);
                oprnds.push(val);
            }
            opertr.pop();
        }
    }
// if some operands are left in stack
    while (opertr.size() > 0)
    {
        char optr = opertr.top();
        opertr.pop();
        int v2 = oprnds.top();
        oprnds.pop();
        int v1 = oprnds.top();
        oprnds.pop();

        int val = operation(v1, v2, optr);
        oprnds.push(val);
    }
    cout << oprnds.top();
    oprnds.pop();
}

int main()
{
    string str;
    getline(cin, str);
    solve(str);
    return 0;
}