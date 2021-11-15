#include <bits/stdc++.h>
using namespace std;
void printInIncreasingandDecresing(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printInIncreasingandDecresing(n-1);
    cout << n << endl;
}
int main()
{
    int n;
    cin >> n;
    printInIncreasingandDecresing(n);
    return 0;
}