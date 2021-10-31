#include <bits/stdc++.h>
using namespace std;
vector<int> NGER(vector<int> a)
{

    vector<int> nge;
    stack<int> st;

    nge.push_back(-1);
    st.push(a[a.size() - 1]);

    for (int i = a.size() - 2; i >= 0; i--)
    {
        while (st.size() > 0 && a.at(i) > st.top())
        {
            st.pop();
        }
        if (st.empty())
        {

            nge.push_back(-1);
        }
        else
        {
            nge.push_back(st.top());
        }
        st.push(a.at(i));
    }
    return nge;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> b = NGER(arr);
    for (int i = b.size() - 1; i >= 0; i--)
    {
        cout << b[i] << endl;
    }

    return 0;
}