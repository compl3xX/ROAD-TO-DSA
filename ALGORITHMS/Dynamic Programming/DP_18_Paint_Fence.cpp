#include <bits/stdc++.h>
using namespace std;
void NOofWays(int n, int k)
{
    int same = k;
    int diff = k * (k - 1);
    int total = same + diff;

    for (int i = 3; i <= n; i++)
    {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }
    cout << total;
}
int main()
{
    int n, k;
    cin >> n >> k;
    NOofWays(n, k);
    return 0;
}