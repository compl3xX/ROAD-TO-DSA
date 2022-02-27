#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> v1, vector<int> v2)
{
    return (v1[0] < v2[0]);
}

void mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), comp);
    stack<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            st.push(arr[0]);
        }
        else
        {
            vector<int> lm = st.top();
            vector<int> cm = arr[i];
            if (lm[1] >= cm[0])
            {
                st.pop();
                vector<int> merge = {lm[0], max(lm[1], cm[1])};
                st.push(merge);
            }
            else
            {
                st.push(cm);
            }
        }
    }
    stack<vector<int>> result;
    while (st.size() > 0)
    {
        result.push(st.top());
        st.pop();
    }
    while (result.size() > 0)
    {
        vector<int> frslt = result.top();
        result.pop();
        cout << frslt[0] << " " << frslt[1] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    mergeOverlappingIntervals(arr);
}