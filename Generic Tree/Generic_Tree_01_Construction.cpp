#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    vector<node *> children;
};
node *newNode(int val)
{
    node *SingleNode = new node;
    SingleNode->data = val;
    return SingleNode;
}
node *constructor(vector<int> arr)
{
    node *root = NULL;
    stack<node *> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            node *t = newNode(arr[i]);
            if (st.size() == 0)
            {
                root = t;
            }
            else
            {
                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }
    return root;
}
void display(node *NODE)
{
    string str = to_string(NODE->data) + "->";
    for (node *child : NODE->children)
    {
        str += to_string(child->data) + ",";
    }
    str += ".";
    cout << str << endl;
    for (node *child : NODE->children)
    {
        display(child);
    }
}
int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1,
                       80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    node *ROOT = constructor(arr);
    display(ROOT);

    return 0;
}