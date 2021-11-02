#include <bits/stdc++.h>
using namespace std;
vector<int> NGER(vector<int> a)
{

    vector<int> nge(a.size());
    stack<int> st;

    nge[0] = -1;
    st.push(a[0]);

    for (int i = 1; i <a.size(); i++)
    {
        while (st.size() > 0 && a[i] > st.top())
        {
            st.pop();
        }
        if (st.empty())
        {

            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(a[i]);
    }
    return nge;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> b = NGER(arr);
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << endl;
    }

    return 0;
}