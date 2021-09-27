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
void middleNode(node *headref)
{
    node *fastpointer = headref;
    node *slowpointer = headref;
    while (fastpointer != NULL && fastpointer->next != NULL)
    {
        slowpointer = slowpointer->next;
        fastpointer = fastpointer->next->next;
    }
    cout << slowpointer->data;
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
    middleNode(head);

    return 0;
}