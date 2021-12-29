#include <bits/stdc++.h>
using namespace std;
// void MinCostNClr(vector<vector<int>> prices)
// {
//     long long dp[prices.size()][prices[0].size()];
//     for (int i = 0; i < prices.size(); i++)
//     {
//         dp[0][i] = prices[0][i];
//     }
//     for (int i = 1; i < prices.size(); i++)
//     {
//         for (int j = 0; j < prices[0].size(); j++)
//         {
//             int min = INT_MAX;
//             for (int k = 0; k < prices[0].size(); k++)
//             {
//                 if (k != j)
//                 {
//                     if (min > dp[i - 1][k])
//                     {
//                         min = dp[i - 1][k];
//                     }
//                 }
//             }
//             dp[i][j] = prices[i][j] + min;
//         }
//     }
//     int min = INT_MAX;
//     for (int k = 0; k < prices[0].size(); k++)
//     {

//         if (min > dp[prices.size() - 1][k])
//         {
//             min = dp[prices.size() - 1][k];
//         }
//     }
//     //cout << min;
// }
void MinCostNClrOP(vector<vector<int>> prices)
{
    long long dp[prices.size()][prices[0].size()];
    long long least = INT_MAX;
    long long sleast = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        dp[0][i] = prices[0][i];
        if (least > prices[0][i])
        {
            sleast = least;
            least = prices[0][i];
        }
        else if (sleast > prices[0][i])
        {
            sleast = prices[0][i];
        }
    }

    for (int i = 1; i < prices.size(); i++)
    {
        long long nleast = INT_MAX;
        long long nsleast = INT_MAX;
        for (int j = 0; j < prices[0].size(); j++)
        {
            if (least == dp[i - 1][j])
            {
                dp[i][j] = sleast + prices[i][j];
            }
            else
            {
                dp[i][j] = least + prices[i][j];
            }
            if (nleast > dp[i][j])
            {
                nsleast = nleast;
                nleast = dp[i][j];
            }
            else if (nsleast > dp[i][j])
            {
                nsleast = dp[i][j];
            }
        }
        least = nleast;
        sleast = nsleast;
    }
    cout << least;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<int>> price(n, vector<int>(k,0));
    for (int i = 0; i < price.size(); i++)
    {
        for (int j = 0; j < price[0].size(); j++)
        {
            cin >> price[i][j];
        }
    }
    //   MinCostNClr(price);
    MinCostNClrOP(price);
    return 0;
}