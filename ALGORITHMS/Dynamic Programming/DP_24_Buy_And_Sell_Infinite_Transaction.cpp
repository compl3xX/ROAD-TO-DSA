#include <iostream>
#include <vector>

using namespace std;

void transactions(vector<int> arr)
{

    int bd = 0;
    int sd = 0;
    int profit = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            sd++;
        }
        else
        {
            profit += arr[sd] - arr[bd];
            sd = bd = i;
        }
    }
    profit += arr[sd] - arr[bd];
    cout << profit;
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