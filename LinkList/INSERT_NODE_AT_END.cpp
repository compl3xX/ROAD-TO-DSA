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

        cout << n->data << " ";
        n = n->next;
    }
}
void append(node **headref, int newdata)
{
    node *newnode = new node;
    node *last = *headref;
    cout << *headref << endl;
    cout << last->next << endl;
    newnode->data = newdata;
    newnode->next = NULL;
    while (last->next != NULL)
    {
        cout << last->next;
        last = last->next;
    }cout << endl;
    cout << newnode;
    
    last->next = newnode;
    return;
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
    append(&head, 4);
    cout << endl;
    printlist(head);

    return 0;
}