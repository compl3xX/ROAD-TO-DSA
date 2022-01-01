#include <bits/stdc++.h>
using namespace std;
void countOfWays(int n, int m)
{
    int dp[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        if (i < m)
        {
            dp[i] = 1;
        }
        else if (i == m)
        {
            dp[i] = 2;
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - m];
        }
    }
    cout << dp[n];
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    countOfWays(n, m);

    return 0;
}