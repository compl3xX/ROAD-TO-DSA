#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack
{

  stack<int> allData;
  stack<int> minData;

public:
  int size()
  {
    return allData.size();
  }

public:
  void push(int val)
  {
    allData.push(val);

    if (minData.size() == 0 || minData.top() >= val)
    {
      minData.push(val);
    }
  }

public:
  int pop()
  {
    if (size() == 0)
    {
      cout << "Stack underflow" << endl;
      return -1;
    }
    else
    {
      int allDatav = allData.top();
      allData.pop();
      if (allDatav == minData.top())
      {
        minData.pop();
      }
      return allDatav;
    }
  }

public:
  int top()
  {
    if (allData.size() == 0)
    {
      cout << "Stack underflow" << endl;
      return -1;
    }
    else
    {
      return allData.top();
    }
  }

public:
  int min()
  {
    if (minData.size() == 0)
    {
      cout << "Stack underflow" << endl;
      return -1;
    }
    else
    {
      return minData.top();
    }
  }
};

int main()
{
  MinStack st;

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
    else if (str == "min")
    {
      int val = st.min();
      if (val != -1)
      {
        cout << val << endl;
      }
    }

    cin >> str;
  }
}