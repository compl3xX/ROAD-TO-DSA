#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> ipt)
{
    stack<int> st;
    for (int i = 0; i < ipt.size(); i++)
    {
        st.push(i);
    }
    while (st.size() >= 2)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if (ipt[i][j] == 1)
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
    }
    int poc = st.top();
    cout << poc << endl;
    st.pop();
    for (int i = 0; i < ipt.size(); i++)
    {
        for (int j = 0; j < ipt.size(); j++)
        {
            cout << ipt[i][j];
        }
    }

    for (int i = 0; i < ipt.size(); i++)
    {
        if (i != poc)
        {
            if (ipt[i][poc] == 0 || ipt[poc][i] == 1)
            {
                cout << "none";
                return;
            }
        }
    }
    cout << poc;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ipt(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ipt[i][j];
        }
    }

    solve(ipt);

    return 0;
}