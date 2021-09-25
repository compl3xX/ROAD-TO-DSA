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
bool search(node *headref, int key)
{

    if (headref == NULL)
    {
        return false;
    }
    if (headref->data == key)
    {
        return true;
    }
    return search(headref->next, key);
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
    push(&head, 2);
    push(&head, 4);
    push(&head, 1);
    push(&head, 3);
    printlist(head);
    search(head, 2) ? cout << "\nYes" : cout << "\nNo";

    return 0;
}
