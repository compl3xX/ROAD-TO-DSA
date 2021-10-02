#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *link;
};
node *top = NULL;
void push(int x)
{
    node *newnode = new node();

    newnode->data = x;
    newnode->link = top;
    top = newnode;
}
void display()

{
    cout << "\n";
    node *temp = top;
    if (temp == NULL)
    {
        return;
    }

    while (temp != NULL)
    {
        cout << "  " << temp->data;
        temp = temp->link;
    }
    cout << "\n";
}
void peek()
{
    if (top == NULL)
    {
        cout << "Empty";
        return;
    }
    cout << top->data;
}
void pop()
{
    node *temp = top;
    if (temp == NULL)
    {
        cout << "Under Flow";
        return;
    }
    cout << "\nPop:-" << temp->data;
    top = temp->link;
    free(temp);
}

int main()
{
    push(2);
    push(3);
    push(4);
    peek();
    display();
    pop();
    display();
    return 0;
}