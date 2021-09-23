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
int getLength(node *headref)
{
    int count = 0;
    node *current = headref;
    while (current != NULL)
    {
        count++;
        current = current->next;
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

    push(&head, 1);
    push(&head, 10);
    push(&head, 11);
    push(&head, 19);
    push(&head, 2);

    printlist(head);
    cout << endl;
    cout << "Length of list:-" << getLength(head) << endl;

    return 0;
}