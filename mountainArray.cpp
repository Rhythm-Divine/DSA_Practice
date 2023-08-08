#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int l = 0;
    int h = arr.size() - 1;
    // 18 29 38 59 98 100 99 90
    //  0  1  2  3  4  5   6  7
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v={18, 29, 38, 59, 98, 100, 99, 90};
    cout<<peakIndexInMountainArray(v)<<endl;
}