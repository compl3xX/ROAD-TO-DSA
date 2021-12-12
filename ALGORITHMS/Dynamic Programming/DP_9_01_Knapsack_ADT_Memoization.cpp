#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int w, int n, vector<vector<int>> &dp)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    int result;
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] <= w)
    {
        result = max((val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, dp)), knapsack(wt, val, w, n - 1, dp));
    }
    else if (wt[n - 1] > w)
    {
        result = knapsack(wt, val, w, n - 1, dp);
    }
    return dp[n][w] = result;
}
int main()

{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    vector<vector<int>> dp(100, vector<int>(100, -1));

    cout << knapsack(wt, val, W, n, dp);

    return 0;
}
