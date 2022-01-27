#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
    int top;

public:
    int a[MAX];
    Stack() { top = -1; }
    void push(int x);
    int pop();
    int peek();
    bool isempty();
};
void Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
    }
    else
    {
        a[++top] = x;
        cout << x << "Pushed into Stack\n";
    }
}
int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
bool Stack::isempty()
{
    return (top < 0);
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from the stack\n ";
    cout << "Elements present in the stack ";
    while (!s.isempty())
    {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}
