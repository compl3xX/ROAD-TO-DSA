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
        return true;
    }
}
void areBracketsBalanced(string str)
{
    stack<char> st;
    for (auto ch : str)
    {

        if (ch == '(' || ch == '{' || ch == '[')
        {

            st.push(ch);
        }

        else if (ch == ')')
        {

            bool val = decision(st, '(');
            if (val == false)
            {

                cout << "false";
                return;
            }
        }
        else if (ch == '}')
        {

            bool val = decision(st, '{');
            if (val == false)
            {
                cout << "false";
                return;
            }
        }
        else if (ch == ']')
        {

            bool val = decision(st, '[');
            if (val == false)
            {

                cout << "false";
                return;
            }
        }
    }

    if (st.empty())
    {

        cout << "true";
    }
    else
    {

        cout << "false";
    }
}

int main()

{
    string expr;
    getline(cin, expr);
    areBracketsBalanced(expr);

    return 0;
}