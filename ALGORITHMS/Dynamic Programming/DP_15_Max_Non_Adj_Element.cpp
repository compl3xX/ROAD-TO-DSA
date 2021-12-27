#include <bits/stdc++.h>
using namespace std;
void MaxNonAdjElement(vector<int> arr)
{
    int inc = arr[0];
    int exc = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int ninc = exc + arr[i];
        int nexc = max(inc, exc);

        inc = ninc;
        exc = nexc;
    }
    cout << max(inc, exc);
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MaxNonAdjElement(arr);

    return 0;
}