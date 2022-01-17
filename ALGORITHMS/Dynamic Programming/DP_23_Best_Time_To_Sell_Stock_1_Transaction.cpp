#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> prices)
{
    int lsf = INT_MAX;
    int op = 0;
    int pist = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < lsf)
        {
            lsf = prices[i];
        }
        pist = prices[i] - lsf;
        if (pist > op)
        {
            op = pist;
        }
    }
    cout << op;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    solve(arr);
    return 0;
}