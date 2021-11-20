#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> getKPC(string s)
{
    if (s.size() == 0)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    char ch = s[0];
    string ros = s.substr(1);
    string arr[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    vector<string> rres = getKPC(ros);
    vector<string> mres;
    string codeforch = arr[ch-'0'];
    for (int i = 0; i < codeforch.length(); i++)
    {

        char chfcode = codeforch[i];

        for (auto str : rres)
        {
            mres.push_back(chfcode + str);
        }
    }
    return mres;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}