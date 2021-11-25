#include <iostream>
using namespace std;

void printSS(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans<<"\n";
        return;
    }

    char ch = ques.at(0);
    string roq = ques.substr(1);
    printSS(roq, ans + ch);
    printSS(roq, ans + "");
}

int main()
{
    string str;
    cin >> str;
    printSS(str, "");
}