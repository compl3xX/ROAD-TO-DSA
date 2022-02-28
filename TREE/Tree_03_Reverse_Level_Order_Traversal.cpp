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
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<int> st;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        st.push(temp->data);
        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout << "Print Level order traversal" << endl;
    levelOrderTraversal(root);
    return 0;
}