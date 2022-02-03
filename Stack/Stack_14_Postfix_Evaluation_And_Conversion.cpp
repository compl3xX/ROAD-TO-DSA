#include <bits/stdc++.h>
using namespace std;
int cal(int v1, int v2, char optr)
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

void solve(string exp)
{
    stack<string> pre;
    stack<string> inf;
    stack<int> val;
    for (int i = 0; i < exp.size(); i++)
    {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9')
        {
            string tmp = string(1, ch);

            pre.push(tmp);
            inf.push(tmp);
            val.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int v2 = val.top();
            val.pop();
            int v1 = val.top();
            val.pop();
            int cval = cal(v1, v2, ch);
            val.push(cval);

            string prev2 = pre.top();
            pre.pop();
            string prev1 = pre.top();
            pre.pop();
            pre.push(ch + prev1 + prev2);

            string infv2 = inf.top();
            inf.pop();

            string infv1 = inf.top();
            inf.pop();

            inf.push('(' + infv1 + ch + infv2 + ')');
        }
    }
    cout << val.top() << endl;
    cout << inf.top() << endl;
    cout << pre.top();
}

int main()
{
    string exp;
    getline(cin, exp);

    solve(exp);
    return 0;
}