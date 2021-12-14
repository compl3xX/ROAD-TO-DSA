#include <bits/stdc++.h>

using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap)
{

    int dp[n + 1][cap + 1] = {};
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < cap + 1; j++)
        {
            if (j >= weight[i - 1])
            {
                int rcap = j - weight[i - 1];
                if (dp[i - 1][rcap] + val[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][rcap] + val[i - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][cap];
}

int main()
{

    int n;
    cin >> n;

    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int cap;
    cin >> cap;

    zeroOneKnapsack(n, val, weight, cap);
}