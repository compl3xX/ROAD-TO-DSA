#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string path)
{

    if (sr == dr && sc == dc)
    {
        cout << path << endl;
        return;
    }
    if (sr > dr || sc > dc || (sr > dr && sc > dc))
    {
        return;
    }

    for (int jmp = 1; jmp <= dc - sc; jmp++)
    {
        //horizontal

        string jump = to_string(jmp);
        printMazePaths(sr, sc + jmp, dr, dc, path + 'h' + jump);
    }

    for (int jmp = 1; jmp <= dr - sr; jmp++)
    {
        //vertical
        string jump = to_string(jmp);
        printMazePaths(sr + jmp, sc, dr, dc, path + 'v' + jump);
    }
    for (int jmp = 1; jmp <= dr - sr && dc - sc; jmp++)
    { 
        //diagonal
        string jump = to_string(jmp);
        printMazePaths(sr + jmp, sc + jmp, dr, dc, path + 'd' + jump);
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}