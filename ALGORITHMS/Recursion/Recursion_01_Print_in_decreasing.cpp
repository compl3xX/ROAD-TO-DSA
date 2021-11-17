#include <bits/stdc++.h>

using namespace std;
void printInDecreasing(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printInDecreasing(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printInDecreasing(n);
    return 0;
}
