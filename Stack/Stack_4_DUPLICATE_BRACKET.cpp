#include <bits/stdc++.h>
using namespace std;
bool findDuplicateparenthesis(string str)
{
    stack<char> st;
    for (auto ch : str)
    {
        if (ch == ')')
        {
            char top = st.top();
            st.pop();
            int elementinside = 0;
            while (top != '(')
            {
                elementinside++;
                top = st.top();
                st.pop();
            }
            if (elementinside < 1)
            {
                return true;
            }
        }
        else
        {
            st.push(ch);
        }
    }
    return false;
}
int main()
{
    string str = "(((a+(b))+(c+d)))";
    if (findDuplicateparenthesis)
    {
        cout << "Duplicate is found";
    }
    else
    {
        cout << "Duplicated is not found ";
    }
    return 0;
}