#include <iostream>
#include <vector>

using namespace std;

void transaction(vector<int> arr)
{
    int ocsp = 0;
    int obsp = -arr[0];
    int ossp = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int ncsp = 0;
        int nbsp = 0;
        int nssp = 0;
        if (ocsp - arr[i] > obsp)
        {
            nbsp = ocsp - arr[i];
        }
        else
        {

            nbsp = obsp;
        }
        if (obsp + arr[i] > ossp)
        {
            nssp = obsp + arr[i];
        }
        else
        {
            nssp = ossp;
        }
        if (ossp > ocsp)
        {
            ncsp = ossp;
        }
        else
        {
            ncsp = ocsp;
        }
        obsp = nbsp;
        ossp = nssp;
        ocsp = ncsp;
    }
    cout << ossp << endl;
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

    transaction(arr);
    return 0;
}
