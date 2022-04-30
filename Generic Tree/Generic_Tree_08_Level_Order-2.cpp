#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

Node *construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = newNode(arr[i]);
            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

void levelorder(Node *node)
{
    queue<Node *> Q;
    Q.push(node);
    Q.push(NULL);
    while (Q.size() > 0)
    {
        Node *rem = Q.front();
        Q.pop();
        if (rem != NULL)
        {
            cout << rem->data << " ";
            for (Node *child : rem->children)
            {
                Q.push(child);
            }
        }
        else
        {
            if (Q.size() > 0)
            {
                cout << "\n";
                Q.push(NULL);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
    levelorder(root);
}