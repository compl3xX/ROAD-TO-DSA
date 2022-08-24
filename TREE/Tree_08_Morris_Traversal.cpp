#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "Enter the data:-";
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for insertion in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for insertion in right" << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void MorrisTraversal(node *root)
{
    node *curr, *prev;
    if (root == NULL)
        return;
    curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    MorrisTraversal(root);

    return 0;
}