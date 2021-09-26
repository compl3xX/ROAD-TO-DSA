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
void push(node **headref, int newdata)
{
    node *new_node = new node();
    new_node->data = newdata;
    new_node->next = (*headref);
    (*headref) = new_node;
}
void getNth(node *headref, int n)
{
    node *current = headref;

    int len = 0;
    while (current != NULL)
    {
        len++;
        current = current->next;
    }
    if (len < n)
    {
        return;
    }

    current = headref;

    for (int i = 1; i < len - n + 1; i++)
    {
        current = current->next;
    }
    cout << current->data;

    return;
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
