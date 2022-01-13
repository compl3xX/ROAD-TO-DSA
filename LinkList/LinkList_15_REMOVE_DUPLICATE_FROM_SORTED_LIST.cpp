
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void duplicate(node *head_ref)
{
    node *current = head_ref;
    node *Dlink;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            Dlink = current->next->next;
            free(current->next);
            current->next = Dlink;
        }
        else
        {
            current = current->next;
        }
    }
}
void push(node **head_ref)
{
    node *new_node = new node();
    cout << "Enter the Data:-";
    int x;
    cin >> x;
    new_node->data = x;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
int main()
{
    struct node *head = NULL;

    push(&head);
    push(&head);
    push(&head);
    push(&head);
    push(&head);
    push(&head);
    printList(head);
    duplicate(head);
    cout << endl;
    printList(head);
    return 0;
}
