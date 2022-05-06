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

    while (Q.size() > 0)
    {
        int cicl = Q.size();
        for (int i = 0; i < cicl; i++)
        {
            Node *chld = Q.front();
            Q.pop();
            cout << chld->data << " ";
            for (Node *child : chld->children)
            {
                Q.push(child);
            }
        }
        cout << "\n";
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