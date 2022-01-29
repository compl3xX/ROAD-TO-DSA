#include <bits/stdc++.h>

using namespace std;
void solve(vector<long long> arr, long long k)
{

    stack<long long> st;
    st.push(arr.size() - 1);
    vector<long long> nge(arr.size());
    nge[arr.size() - 1] = arr.size();
    for (long long i = arr.size() - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] >= arr[st.top()])
        {

            st.pop();
        }
        if (st.size() == 0)
        {

            nge[i] = arr.size();
        }
        else
        {

            nge[i] = st.top();
        }
        st.push(i);
    }

    long long j = 0;
    for (long long i = 0; i <= arr.size() - k; i++)
    {
        if (j < i)
        {
            j = i;
        }
        while (nge[j] < i + k)
        {
            j = nge[j];
        }
        cout << arr[j] << " ";
    }
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long k;
    cin >> k;

    solve(arr, k);

    return 0;
}
