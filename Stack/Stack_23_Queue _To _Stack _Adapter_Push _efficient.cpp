#include <iostream>
#include <exception>
#include <queue>
using namespace std;

class QueueToStackAdapter
{
public:
    queue<int> mainQ;
    queue<int> helperQ;

    int size()
    {
        return mainQ.size();
    }

    void push(int data)
    {
        mainQ.push(data);
    }

    int top()
    {
        if (mainQ.size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        while (mainQ.size() > 1)
        {
            int r = mainQ.front();
            mainQ.pop();
            helperQ.push(r);
        }
        int rem = mainQ.front();
        mainQ.pop();
        helperQ.push(rem);
        while (helperQ.size() > 0)
        {
            int temp = helperQ.front();
            helperQ.pop();
            mainQ.push(temp);
        }
        return rem;
    }

    int pop()
    {
        if (mainQ.size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        while (mainQ.size() > 1)
        {
            int r = mainQ.front();
            mainQ.pop();
            helperQ.push(r);
        }
        int rem = mainQ.front();
        mainQ.pop();
        while (helperQ.size() > 0)
        {
            int temp = helperQ.front();
            helperQ.pop();
            mainQ.push(temp);
        }
        return rem;
    }
};

int main()
{
    QueueToStackAdapter st;
    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "push")
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (str == "pop")
        {
            int val = st.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "top")
        {
            int val = st.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        cin >> str;
    }
    return 0;
}