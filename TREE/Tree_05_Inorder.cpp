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
void inOrder(node *root)
{
    stack<node *> st;

    node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    inOrder(root);

    return 0;
}