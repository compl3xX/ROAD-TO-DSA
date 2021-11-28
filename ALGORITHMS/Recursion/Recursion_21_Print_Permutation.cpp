#include <iostream>
using namespace std;

void printPermutations(string str, string res)
{
    if (str.length() == 0)
    {
        cout << res << endl;
        return;
    }

    for (int selch = 0; selch < str.length(); selch++)
    {

        char ch = str[selch];
        
        string ros = str.substr(0, selch) + str.substr(selch+1);

        printPermutations(ros, res + ch);
    }
}

int main()
{
    string str;
    cin >> str;
    printPermutations(str, "");
}