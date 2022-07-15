#include <bits/stdc++.h>
using namespace std;
int solveRecursion(int m, int n, int i, int j)
{
    if (i >= m || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;
    return solveRecursion(m, n, i + 1, j) + solveRecursion(m, n, i, j + 1);
}
int solveMemoiztion(vector<vector<int>> &dp, int i, int j)
{
    if (i >= dp.size() || j >= dp[0].size())
        return 0;
    if (i == dp.size() - 1 && j == dp[0].size() - 1)
        return 1;
    if (dp[i][j] != 0)
        return dp[i][j];
    return dp[i][j] = solveMemoiztion(dp, i + 1, j) + solveMemoiztion(dp, i, j + 1);
}
int solveTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[m - 1][n - 1];
}
int solveSpaceOptimiz(int m, int n)
{
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {

            if (j == 0)
            {

                temp[j] = dp[j];
            }
            else
            {
                temp[j] = dp[j] + temp[j - 1];
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}
int main()
{
    int n, m;
    cin >> m >> n;
    cout << "Recursion:-" << solveRecursion(m, n, 0, 0) << endl;
    vector<vector<int>> dp(m, vector<int>(n));
    cout << "Memoization:-" << solveMemoiztion(dp, 0, 0) << endl;
    cout << "Tabulation:-" << solveTabulation(m, n) << endl;
    cout << "Space Optimization:-" << solveSpaceOptimiz(m, n);
    return 0;
}