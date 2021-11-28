#include <bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar)
{
    if (idx == arr.size())
    {
        if (sos == tar)
        {
            cout << set << "." << endl;
        }
        return;
    }
    if (sos > tar)
    {
        return;
    }

    string ch = to_string(arr[idx]);
    printTargetSumSubsets(arr, idx + 1, set + ch + ", ", sos + arr[idx], tar);
    printTargetSumSubsets(arr, idx + 1, set, sos, tar);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int grtn;
    cin >> grtn;
    printTargetSumSubsets(arr, 0, "", 0, grtn);
}