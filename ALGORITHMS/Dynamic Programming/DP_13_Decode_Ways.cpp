#include <bits/stdc++.h>
using namespace std;
void count_Decode_Ways(string str)
{
   
    int dp[str.size()];
    dp[0] = 1;
    for (int i = 1; i < str.size(); i++)
    {

        if (str[i] == '0' && str[i - 1] == '0')
        {
            dp[i] = 0;
        }
        else if (str[i - 1] == '0' && str[i] != '0')
        {
            dp[i] = dp[i - 1];
        }
        else if (str[i] == '0' && str[i - 1] != '0')
        {
            if (str[i - 1] == '2' || str[i - 1] == '1')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 1);
            }
            else
            {
                dp[i] = 0;
            }
        }
        else
        {
            int nonzero = stoi(str.substr(i - 1, 2));
            if (nonzero <= 26)
            {
                dp[i] = dp[i-1]+(i >= 2 ? dp[i - 2] : 1);
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
    }
    cout << dp[str.size()-1];
}
int main()
{
    string str;
    cin >> str;
    count_Decode_Ways(str);
    return 0;
}