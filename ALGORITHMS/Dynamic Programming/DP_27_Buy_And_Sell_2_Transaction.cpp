#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int> arr)
{
    int mpist = 0;
    int lsof = arr[0];
    int dpLR[arr.size()]={};
    //L->R
    for (int i = 1; i < arr.size(); i++)
    {
        if (lsof > arr[i])
        {
            lsof = arr[i];
        }
      //  cout << lsof<<endl;
        mpist = arr[i] - lsof;
        dpLR[i] = mpist;
        if (dpLR[i] < dpLR[i - 1])
        {
            dpLR[i] = dpLR[i - 1];
        }
    }
   // cout << dpLR[arr.size() - 1] << endl;
    //R->L
    int mpibtb = 0;
    int maxof = arr[arr.size()-1];
    int dpRL[arr.size()]={};
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (maxof < arr[i])
        {
            maxof = arr[i];
        }
        mpibtb = maxof - arr[i];
        dpRL[i] = mpibtb;

        if (dpRL[i] < dpRL[i - 1])
        {
            dpRL[i] = dpLR[i - 1];
        }
    }

    int op = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (dpLR[i] + dpRL[i] > op)
        {
            op = dpLR[i] + dpRL[i];
        }
    }
    cout << op;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    transactions(arr);

    return 0;
}