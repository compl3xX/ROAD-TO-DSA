#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s)
{
    if (s.size() == 0)

    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    char ch = s[0];
    string ros = s.substr(1);
    vector<string> rres = gss(ros);
    vector<string> fres;
    for (auto str : rres)
    {
        fres.push_back(str);
    }
    for (auto str : rres)
    {
        fres.push_back(ch + str);
    }
    return fres;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';

    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
        cout << cnt;
    }
    cout << ']';
}
