#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

void printlist(node *n)
{
    while (n != NULL)
    {
        //cout << n;
        cout << n->data << " ";
        n = n->next;
    }
}
int getNth(node *headref, int n)
{

    if (headref == NULL)
    {
        return 0;
    }
    int count = getNth(headref->next, n) + 1;
    if (count == n)
    {
        cout << headref->data;
    }
    return count;
}
void push(node **headref, int newdata)
{
    node *new_node = new node();
    new_node->data = newdata;
    new_node->next = (*headref);
    (*headref) = new_node;
}

int main()
{
    node *head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 1);
    push(&head, 10);
    push(&head, 8);
    push(&head, 7);

    printlist(head);
    cout << endl;
    getNth(head, 3);

    return 0;
}