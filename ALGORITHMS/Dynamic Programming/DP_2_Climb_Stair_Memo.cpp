#include <bits/stdc++.h>
using namespace std;

int climbstair(int n, vector<int> &qb)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    if (qb[n] > 0)
    {
        return qb[n];
    }
    int nm1 = climbstair(n - 1, qb);
    int nm2 = climbstair(n - 2, qb);
    int nm3 = climbstair(n - 3, qb);
    int cp = nm1 + nm2 + nm3;
    qb[n] = cp;
    return cp;
}

int main()
{
    int n;
    cin >> n;
    vector<int> qb(n + 1);
    cout << climbstair(n, qb) << endl;
}