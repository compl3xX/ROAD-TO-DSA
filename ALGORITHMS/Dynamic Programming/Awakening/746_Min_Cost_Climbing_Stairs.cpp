#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// RECURSION
int solver(int start, vector<int> &cost)
{
    int res = 0;
    if (start >= cost.size())
    {
        return 0;
    }

    res = cost[start] + min(solver(start + 1, cost), solver(start + 2, cost));

    return res;
}
int minClimbStair(vector<int> &cost)
{
    int n = cost.size();
    int minCost = min(solver(0, cost), solver(1, cost));

    return minCost;
}
// MEMOIZATION
int solverMemo(int start, vector<int> &cost, vector<int> dp)
{
    int res = 0;
    if (start >= cost.size())
    {
        return 0;
    }
    if (dp[start] != 0)
        return dp[start];

    dp[start] = cost[start] + min(solver(start + 1, cost), solver(start + 2, cost));

    return dp[start];
}
int minClimbMemo(vector<int> &cost, vector<int> dp)
{
    int minCost = min(solverMemo(0, cost, dp), solverMemo(0, cost, dp));
    return minCost;
}
// TABULATION
int minCostTab(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[n - 1], dp[n - 2]);
}
// Space Optimization
int minCostOptimz(vector<int> &cost)
{
    int n = cost.size();
    int prev = 0;
    int secPrev = 0;
    for (int i = 2; i <= n; i++)
    {
        int jumpOne = prev + cost[i - 1];
        int jumptwo = secPrev + cost[i - 2];
        secPrev = prev;
        prev = min(jumpOne, jumptwo);
    }
    return prev;
}
int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minClimbStair(cost);
    vector<int> dp(cost.size(), 0);

    cout << endl
         << minClimbMemo(cost, dp);

    cout << endl
         << minCostTab(cost);
    cout << endl
         << minCostOptimz(cost);
    return 0;
}