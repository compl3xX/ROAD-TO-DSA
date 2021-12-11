#include <bits/stdc++.h>
using namespace std;
string printString(string s)
{
    if (s.size() == 0)
    {
        string blank;
        return blank;
    }
    char ch = s[0];
    
    string ros = s.substr(1);
    string rstr = printString(ros);
    string ans = rstr + ch;
    return ans;
}
int main()
{
    string str;
    cin >> str;
    cout << printString(str);
    return 0;
}