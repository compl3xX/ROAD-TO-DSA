#include <bits/stdc++.h>
using namespace std;
void countOfWays(int n)
{
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    cout << dp[n];
}
int main()
{
    int n;
    cin >> n;

    countOfWays(n);

    return 0;
}