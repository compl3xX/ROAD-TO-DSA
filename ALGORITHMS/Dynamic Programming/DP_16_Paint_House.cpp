#include <bits/stdc++.h>
using namespace std;
void minCost(vector<vector<int>> price)
{
    long long dp[price.size()][price[0].size()];
    dp[0][0] = price[0][0];
    dp[0][1] = price[0][1];
    dp[0][2] = price[0][2];
    for (int i = 1; i < price.size(); i++)
    {
        dp[i][0] = price[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = price[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = price[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    long long mingb = min(dp[price.size() - 1][1], dp[price.size() - 1][2]);
    long long ans = min(mingb, dp[price.size() - 1][0]);
    cout << ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> price(n, vector<int>(3));
    for (int i = 0; i < price.size(); i++)
    {
        for (int j = 0; j < price[0].size(); j++)
        {
            cin >> price[i][j];
        }
    }
    minCost(price);

    return 0;
}