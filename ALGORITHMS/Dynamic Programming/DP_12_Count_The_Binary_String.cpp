#include <bits/stdc++.h>
using namespace std;
void countBinarystring(int size)
{
    int dp[2][size + 1];
    dp[0][1] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < size + 1; i++)
    {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
    }
    cout << dp[1][size] + dp[0][size] << endl;
    //Space Optimisation
    int oczeros = 1;
    int ocones = 1;
    for (int i = 2; i < size + 1; i++)
    {
        int nczeros = ocones;
        int ncones = ocones + oczeros;
        oczeros = nczeros;
        ocones = ncones;
    }
    cout << oczeros + ocones;
}
int main()
{
    int str;
    cin >> str;
    countBinarystring(str);

    return 0;
}