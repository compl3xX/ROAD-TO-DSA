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
    cout << "\n";
}
void deletenode(node **headref, int key)
{
    if (*headref == NULL)
    {
        return;
    }
    node *temp = *headref;
    if (key == 0)
    {
        *headref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < key - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        cout << "\nNO ELEMENT IS PRESENT ON THIS POSITION\n";
        return;
    }

    node *next = temp->next->next;

    free(temp->next);
    temp->next = next;
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

    push(&head, 4);
    push(&head, 6);
    push(&head, 5);
    printlist(head);
    deletenode(&head, 7);
    cout << "\n";
    printlist(head);

    return 0;
}
