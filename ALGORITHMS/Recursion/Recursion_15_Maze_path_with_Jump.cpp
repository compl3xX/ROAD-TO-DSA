#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
{

    // base case
    if (sr == dr && sc == dc)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    else if (sr > dr || sc > dc)
    {
        vector<string> bres;
        return bres;
    }
    vector<string> paths;
    //horizontal moves

    for (int js = 1; js <= dc - sc; js++)
    {
        auto jmps = to_string(js);
        vector<string> hpaths = get_maze_paths(sr, sc + js, dr, dc);
        for (auto hpath : hpaths)
        {
            paths.push_back("h" +jmps+ hpath);
        }
    }
    // vertical moves
    for (int js = 1; js <= dr - sr; js++)
    {
        auto jmps = to_string(js);
        vector<string> vpaths = get_maze_paths(sr + js, sc, dr, dc);
        for (auto vpath : vpaths)
        {
            paths.push_back("v" + jmps + vpath);
        }
    }
    //diagonal moves
    for (int js = 1; js <= dr - sr && js <= dc - sc; js++)
    {
        auto jmps = to_string(js);
        vector<string> dpaths = get_maze_paths(sr + js, sc + js, dr, dc);
        for (auto dpath : dpaths)
        {
            paths.push_back("d" + jmps + dpath);
        }
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
    vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}