#include <iostream>
#include <vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    vector<string> hpaths;
    vector<string> vpaths;
    if (sc < dc)
    {
        hpaths = getMazePaths(sr, sc + 1, dr, dc);
    }
    if (sr < dr)
    {
        vpaths = getMazePaths(sr + 1, sc, dr, dc);
    }
    vector<string> paths;
    for (auto path : hpaths)
    {
        paths.push_back('h' + path);
    }
    for (auto path : vpaths)
    {
        paths.push_back('v' + path);
    }
    return paths;
}

void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = getMazePaths(1, 1, n, m);
    display(ans);

    return 0;
}