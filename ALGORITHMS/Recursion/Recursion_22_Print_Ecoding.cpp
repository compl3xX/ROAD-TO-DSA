#include <iostream>
#include <string>
using namespace std;

void printEncoding(string str, string asf)
{
    if (str.length() == 0)
    {
        cout << asf << endl;
        return;
    }
    else if (str.length() == 1)
    {
        char ch = str.at(0);
        if (ch == '0')
        {
            return;
        }
        else
        {
            int chv = ch - '0';
            char code = 'a' + chv - 1;
            asf = asf + code;
            cout << asf << endl;
        }
    }
    else
    {
        char ch = str.at(0);
        string ros = str.substr(1);
        if (ch == '0')
        {
            return;
        }
        else
        {
            int chv = ch - '0';
            char code = 'a' + chv - 1;
            printEncoding(ros, asf + code);
        }

        string ch12 = str.substr(0, 2);
        ros = str.substr(2);
        int ch12v = stoi(ch12);
        if (ch12v <= 26)
        {

            char code = 'a' + ch12v - 1;
            printEncoding(ros, asf + code);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    printEncoding(str, "");
}