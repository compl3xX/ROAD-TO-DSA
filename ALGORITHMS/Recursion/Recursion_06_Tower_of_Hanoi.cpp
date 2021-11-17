#include <bits/stdc++.h>
using namespace std;
void tdh(int n, int t1d, int t2d, int t3d)
{
    if (n == 0)
    {
        return;
    }
    tdh(n - 1, t1d, t3d, t2d);
    cout << n << "[" << t1d << "->" << t2d << "]"<<endl;
    tdh(n - 1, t3d, t2d, t1d);
}
int main()
{
    int n;
    cin >> n;
    tdh(n, 10, 11, 12);
    return 0;
}
