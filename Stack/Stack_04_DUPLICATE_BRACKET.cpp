#include <bits/stdc++.h>
using namespace std;
void findDuplicateparenthesis(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str.at(i);
        if (ch == ')')
        {
            if (st.top() == '(')
            {

                cout << "true";
                return;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }
    cout << "false";
}
int main()
{
    string str;
    getline(cin, str);
    findDuplicateparenthesis(str);
    return 0;
}
