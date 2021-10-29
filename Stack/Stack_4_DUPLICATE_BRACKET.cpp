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
                return 1;
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
    string str;
    cin>>str;
     getline(cin, str);
    if (findDuplicateparenthesis(str))
    {
        cout << "Duplicate is found";
    }
    else
    {
        cout << "Duplicated is not found ";
    }
    return 0;
}
