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
int getnth(node *headref, int idx)
{
    node *current = headref;
    int count = 0;
    while (current != NULL)
    {
        if (count == idx)
        {
            return (current->data);
        }
        count++;
        current = current->next;
    }
   assert(0);
}

int main()
{
    node *head = NULL;

    push(&head, 4);
    push(&head, 1);
    push(&head, 8);
    push(&head, 10);
    push(&head, 3);

    printlist(head);
    cout << endl;
    cout << getnth(head,2);


    return 0;
}
