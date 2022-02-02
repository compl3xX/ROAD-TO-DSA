#include <bits/stdc++.h>

using namespace std;
int precedence(char optr)
{
    if (optr == '+')
    {
        return 1;
    }
    else if (optr == '-')
    {
        return 1;
    }
    else if (optr == '*')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}
void solve(string str)
{
    stack<string> pre;
    stack<string> post;
    stack<char> oprtr;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(')
        {
            oprtr.push(ch);
        }
        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            string tmp = string(1, ch);

            pre.push(tmp);
            post.push(tmp);
        }
        else if (ch == ')')
        {
            while (oprtr.top() != '(')
                {
                    char opr = oprtr.top();
                    oprtr.pop();

                    string postv2 = post.top();
                    post.pop();
                    string postv1 = post.top();
                    post.pop();

                    post.push(postv1 + postv2 + opr);

                    string prev2 = pre.top();
                    pre.pop();
                    string prev1 = pre.top();
                    pre.pop();
                    pre.push(opr + prev1 + prev2);
                }

            oprtr.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (oprtr.size() > 0 && oprtr.top() != '(' && precedence(ch) <= precedence(oprtr.top()))
            {
                char opr = oprtr.top();
                oprtr.pop();

                string postv2 = post.top();

                post.pop();
                string postv1 = post.top();
                post.pop();
                post.push(postv1 + postv2 + opr);

                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();

                pre.push(opr + prev1 + prev2);
            }
            oprtr.push(ch);
        }
    }
    while (oprtr.size() > 0)
    {

        string postv2 = post.top();
        post.pop();
        string postv1 = post.top();
        post.pop();
        char opr = oprtr.top();
        oprtr.pop();
        post.push(postv1 + postv2 + opr);

        string prev2 = pre.top();
        pre.pop();
        string prev1 = pre.top();
        pre.pop();

        pre.push(opr + prev1 + prev2);
    }
    cout << post.top() << endl;
    cout << pre.top();
}

int main()
{
    string str;
    getline(cin, str);

    solve(str);

    return 0;
}