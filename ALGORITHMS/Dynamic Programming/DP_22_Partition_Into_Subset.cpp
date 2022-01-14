#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k)
{
    long long dp[k + 1][n + 1] = {};
    if (n == 0 || k == 0 || n < k)
    {
        cout << 0 << endl;
        return;
    }
    for (int t = 1; t < k + 1; t++)
    {
        for (int p = 1; p < n + 1; p++)
        {
            if (t > p)
            {
                dp[t][p] = 0;
            }
            else if (t == p)
            {
                dp[t][p] = 1;
            }
            else
            {
                dp[t][p] = dp[t - 1][p - 1] + dp[t][p - 1] * t;
            }
        }
    }
    cout << dp[k][n];
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    solve(n, k);
    return 0;
}