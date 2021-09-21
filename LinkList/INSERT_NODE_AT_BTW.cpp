#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
void insertAfter(node *prev_node, int newdata)
{
    if (prev_node == NULL)
    {
        cout << "previous node cannot be NULL";
        return;
    }
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = prev_node->next;
    prev_node->next = newnode;
}
void printlist(node *n)
{
    while (n != NULL)
    {
        //cout << n;
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printlist(head);
    insertAfter(head, 4);
    cout << "\n";
    printlist(head);

    return 0;
}