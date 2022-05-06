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
class Pair
{
public:
    Node *node;
    int level;
    Pair(Node *node, int level)
    {
        this->node = node;
        this->level = level;
    }
};
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
    queue<Pair> Q;
    Q.push(Pair(node, 1));
    int level = 1;

    while (Q.size() > 0)
    {
        Pair rem = Q.front();
        Q.pop();
        if (rem.level > level)
        {
            cout << "\n";
            level = rem.level;
        }
        cout << rem.node->data << " ";
        for (Node *child : rem.node->children)
        {
            Q.push(Pair(child, rem.level + 1));
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