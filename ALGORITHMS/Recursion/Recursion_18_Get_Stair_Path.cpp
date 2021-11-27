#include <iostream>
using namespace std;

void printStairPaths(int n, string path)
{
    if (n == 0)
    {
        cout << path << endl;
        return;
    }
    else if (n < 0)
    {
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        auto step = to_string(i);
        printStairPaths(n - i, path + step);
    }
}

int main()
{

    int n;
    cin >> n;
    printStairPaths(n, "");
}