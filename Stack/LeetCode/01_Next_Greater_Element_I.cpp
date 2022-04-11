#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &arr)
{
    vector<int> nge(arr.size(), 0);
    stack<int> st;
    nge[arr.size() - 1] = -1;
    st.push(arr[arr.size() - 1]);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] >= st.top())
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }

    // return nge;
    vector<int> nge2(nums1.size(), 0);
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nge.size(); j++)
        {
            if (nums1[i] == arr[j])
            {
                nge2[i] = nge[j];
            }
        }
    }

    return nge2;
}
int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> out = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}
