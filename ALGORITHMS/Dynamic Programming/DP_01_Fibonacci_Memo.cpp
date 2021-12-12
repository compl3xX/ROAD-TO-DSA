#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &qb)
{
    
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (qb[n] != 0)
    {
        return qb[n];
    }
    int fbn1 = fib(n - 1, qb);
    int fbn2 = fib(n - 2, qb);
    int fbn = fbn1 + fbn2;
    qb[n] = fbn;
    return fbn;
}

int main()
{
    int n;
    cin >> n;
    vector<int> qn(n + 1);
    cout << fib(n, qn) << endl;
    return 0;
}