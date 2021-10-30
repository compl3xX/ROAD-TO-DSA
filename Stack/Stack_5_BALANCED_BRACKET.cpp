#include <bits/stdc++.h>
using namespace std;
bool decision(stack<char> &st1, char ch1)
{

    if (st1.size() == 0)
    {

        return false;
    }
    else if (st1.top() != ch1)
    {

        return false;
    }
    else
    {

        st1.pop();
    }
}
bool areBracketsBalanced(string str)
{
    stack<char> st;
    for (auto ch : str)
    {
        //cout << ch;
        if (ch == '(' || ch == '{' || ch == '[')
        {

            st.push(ch);
        }
        else
        {

            if (ch == ')')
            {

                if (decision(st, '(') == 0)
                {

                    return decision(st, '(');
                }
            }
            else if (ch == '}')
            {

                if (decision(st, '{') == 0)
                {

                    return decision(st, '{');
                }
            }
            else if (ch == ']')
            {

                if (decision(st, '[') == 0)
                {

                    return decision(st, '[');
                }
            }
        }
    }

    if (st.empty())
    {

        return true;
    }
    else
    {

        return false;
    }
}

int main()

{
    string expr;
    getline(cin, expr);

    if (areBracketsBalanced(expr) == 1)
        cout << "true";
    else
        cout << "false";
    return 0;
}
