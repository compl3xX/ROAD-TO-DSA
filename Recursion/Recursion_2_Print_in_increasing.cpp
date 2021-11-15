#include <bits/stdc++.h>
using namespace std;
void printInIncreasing(int n)
{
    if (n == 0)
    {
        return;
    }
    printInIncreasing(n - 1);
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;
    printInIncreasing(n);
    return 0;
}