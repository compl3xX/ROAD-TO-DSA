#include <bits/stdc++.h>
using namespace std;
int binarysearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {

            return mid;
        }
        if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int main()

{
    int arr[] = {2, 5, 10, 11, 12, 13};
    int x = 10;
    int n = 6;
    int result = binarysearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;

    return 0;
}
