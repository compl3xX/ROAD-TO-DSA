#include <bits/stdc++.h>

using namespace std;

int collectGold(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    for (int j = arr[0].size() - 1; j >= 0; j--)

    {
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (j == arr[0].size() - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else if (i == arr.size() - 1)
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            else
            {
                int mxofd = max(dp[i + 1][j + 1], dp[i - 1][j + 1]);
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], mxofd);
            }
        }
    }
    int max = dp[0][0];
    for (int i = 1; i < dp.size(); i++)
    {
        if (dp[i][0] > max)
        {
            max = dp[i][0];
        }
    }
    
    return max;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));

    cout << collectGold(n, m, arr, dp);
}