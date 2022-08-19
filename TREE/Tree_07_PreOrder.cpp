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
    cout << "Enter the Data:-";
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right node of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void PreOrder(node *root)
{

    if (root == NULL)
        return;

    stack<node *> st;
    node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            st.push(curr->right);
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    PreOrder(root);

    return 0;
}