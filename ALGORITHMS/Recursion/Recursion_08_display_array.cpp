#include <iostream>
using namespace std;

void displayArr(int arr[], int idx, int n)
{
    if (idx == n)
    {
        return;
    }
    cout << arr[idx] << endl;
    displayArr(arr, idx + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    displayArr(arr, 0, n);
}
