#include <iostream>
using namespace std;

void displayArrinReverse(int arr[], int idx, int n)
{
    if (idx == n)
    {
        return;
    }
    displayArrinReverse(arr, idx + 1, n);
    cout << arr[idx] << endl;
    
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    displayArrinReverse(arr, 0, n);
}