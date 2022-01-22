#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int> arr, int k)
{
    int dp[k + 1][arr.size()] = {};
    for (int nt = 1; nt < k + 1; nt++)
    {
        for (int day = 1; day < arr.size(); day++)
        {
            int ntsnc = dp[nt][day - 1];

            for (int nm1t = 0; nm1t < day; nm1t++)
            {
                int tod = dp[nt - 1][nm1t] + (arr[day] - arr[nm1t]);
                if (tod > ntsnc)
                {
                    ntsnc = tod;
                }
            }

            dp[nt][day] = ntsnc;
        }
    }
    cout << dp[k][arr.size() - 1] << endl;
}
void transactionsopt(vector<int> arr, int k)
{
    int dp[k + 1][arr.size()] = {};
    for (int nt = 1; nt < k + 1; nt++)
    {
        int MaX = INT_MIN;
        for (int day = 1; day < arr.size(); day++)
        {

            MaX = max(MaX, dp[nt - 1][day - 1] - arr[day - 1]);
            if (MaX + arr[day] > dp[nt][day - 1])
            {
                dp[nt][day] = MaX + arr[day];
            }
            else
            {
                dp[nt][day] = dp[nt][day - 1];
            }
        }
    }
    cout << dp[k][arr.size() - 1];
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    transactions(arr, k);
    transactionsopt(arr, k);

    return 0;
}