#include <bits/stdc++.h>
using namespace std;
vector<int> NGER(vector<int> arro)
{
    vector<int> nge(arro.size());
    stack<int> st;
    st.push(0);

    for (int i = 1; i < arro.size(); i++)
    {
        while (st.size() > 0 && arro[i] > arro[st.top()])
        {
            int pos = st.top();
            nge[pos] = arro[i];
            st.pop();
        }
        st.push(i);
    }
    while (st.size() > 0)
    {
        int pos = st.top();
        nge[pos] = -1;
        st.pop();
    }

    return nge;
}
int main()
{
    int n;
    cin >> n;
    vector<int> iarr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> iarr[i];
    }
    vector<int> opt = NGER(iarr);
    for (int i = 0; i < opt.size(); i++)
    {
        cout << opt[i]<<" ";
    }

    return 0;
}