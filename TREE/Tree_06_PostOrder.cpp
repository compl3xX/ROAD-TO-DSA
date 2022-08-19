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
void PostOrder1S(node *root)
{
    cout << endl;
    stack<node *> st;
    node *cur = root;
    while (cur != NULL || !st.empty())
    {
        while (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        node *temp = st.top()->right;
        if (temp == NULL)
        {
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            while (!st.empty() && temp == st.top()->right)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
            }
        }
        else
        {
            cur = temp;
        }
    }
}
void PostOrder2S(node *root)
{
    stack<node *> st1;
    stack<node *> st2;
    node *curr = root;

    st1.push(curr);
    while (!st1.empty())
    {
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left != NULL)
        {
            st1.push(curr->left);
        }
        if (curr->right != NULL)
        {
            st1.push(curr->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
    cout << endl;
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    PostOrder1S(root);
    PostOrder2S(root);

    return 0;
}