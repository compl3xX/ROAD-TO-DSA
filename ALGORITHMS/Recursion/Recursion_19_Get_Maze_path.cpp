#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string paths)
{
    if (sr == dr && sc == dc)
    {
        cout << paths << endl;
        return;
    }
    else if (sr > dr || sc > dc)
    {
        return;
    }

    //vertical
    printMazePaths(sr + 1, sc, dr, dc, paths + 'v');
    //horizontal

    printMazePaths(sr, sc + 1, dr, dc, paths + 'h');
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}