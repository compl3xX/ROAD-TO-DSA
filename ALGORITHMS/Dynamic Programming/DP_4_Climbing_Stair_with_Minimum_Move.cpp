#include <bits/stdc++.h>

using namespace std;

int jumpT(int i, int n, vector<int> &jumps, vector<int> &dp)
{
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (jumps[i] > 0)
        {
            int minV = INT_MAX;
            for (int j = 1; j <= jumps[i] && i + j < dp.size(); j++)
            {
                if (dp[i + j] != -1)
                {
                    minV = min(minV, dp[i + j]);
                }
            }
            if (minV != INT_MAX)
            {
                dp[i] = minV + 1;
            }
        }
    }
    return dp[0];
}

int main()
{

    int n;
    cin >> n;

    vector<int> jumps(n);

    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }

    vector<int> dp(n + 1, -1);

    int ans = jumpT(0, n, jumps, dp);

    if (ans < 30)
        cout << ans;
    else
        cout << "null";
}