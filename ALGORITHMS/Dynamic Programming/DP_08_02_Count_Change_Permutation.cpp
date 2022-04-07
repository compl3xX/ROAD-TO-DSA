#include <iostream>
#include <vector>
using namespace std;

int CCP(vector<int> coins, int amt, vector<int> dp)
{

    dp[0] = 1;
    for (int elemt = 1; elemt <= amt; elemt++)
    {
        for (int coin : coins)
        {
            if (coin <= elemt)
            {
                int ramt = elemt - coin;
                dp[elemt] += dp[ramt];
            }
        }
    }

    return dp[amt];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n, 0);
    for (int i = 0; i < coins.size(); i++)
    {
        cin >> coins[i];
    }
    int amt;
    cin >> amt;
    vector<int> dp(amt + 1, 0);
    cout << CCP(coins, amt, dp);
}