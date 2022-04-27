#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Node

{

public:
    int data = 0;

    vector<Node *> children;

    Node(int data)

    {

        this->data = data;
    }
};

Node *constructor01(vector<int> &arr)

{

    if (arr.size() == 0)

        return NULL;

    vector<Node *> stack;

    stack.push_back(new Node(arr[0]));

    Node *root = stack[0];

    for (int i = 1; i < arr.size(); i++)

    {

        if (arr[i] != -1)

        {

            Node *node = stack.back();

            Node *nnode = new Node(arr[i]);

            node->children.push_back(nnode);

            stack.push_back(nnode);
        }

        else

            stack.pop_back();
    }

    return root;
}
void levelOderZigZag(Node *node)

{

    stack<Node *> ms;
    ms.push(node);
    stack<Node *> cs;
    int level = 1;
    while (ms.size() > 0)
    {
        Node *tmp = ms.top();
        ms.pop();
        cout << tmp->data << " ";
        if (level % 2 == 1)
        {
            for (Node *child : tmp->children)
                cs.push(child);
        }
        else
        {
            for (int i = tmp->children.size() - 1; i >= 0; i--)
            {
                cs.push(tmp->children[i]);
            }
        }
        if (ms.size() == 0)
        {
            swap(ms, cs);
            cout << endl;
            level++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = constructor01(arr);
    levelOderZigZag(root);
}

int main()
{
    solve();
    return 0;
}