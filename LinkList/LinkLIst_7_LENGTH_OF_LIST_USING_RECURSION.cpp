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

int getcount(node *headref)
{
    if (headref == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getcount(headref->next);
    }
}

int main()
{
    node *head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 1);
    push(&head, 3);
   
    printlist(head);

    cout << "Length of list:-" << getcount(head);

    return 0;
}
