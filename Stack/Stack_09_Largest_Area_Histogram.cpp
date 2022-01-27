#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> arr)
{
    //Right Boundary
    int rb[arr.size()];
    stack<int> st;
    st.push(arr.size() - 1);
    rb[arr.size() - 1] = arr.size();
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            rb[i] = arr.size();
        }
        else
        {
            rb[i] = st.top();
        }
        st.push(i);
    }
    //left boundary
    int lb[arr.size()];
    stack<int> st2;
    st2.push(0);
    lb[0] = -1;
    for (int i = 1; i < arr.size(); i++)
    {
        while (st2.size() > 0 && arr[i] <= arr[st2.top()])
        {
            st2.pop();
        }
        if (st2.size() == 0)
        {
            lb[i] = -1;
        }
        else
        {
            lb[i] = st2.top();
        }
        st2.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int width = rb[i] - lb[i] - 1;
        int area = arr[i] * width;
        if (area > maxArea)
        {
            maxArea = area;
        }
    }
   
    return maxArea;
}
int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr);

    return 0;
}