#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int s, int mid, int e)
{
    int l1 = mid + 1 - s;
    int l2 = e - mid;
    vector<int> leftSubArray;
    vector<int> rightSubArray;
    int indexOfMainArray = s;

    for (int i = 0; i < l1; i++)
    {
        // leftSubArray[i] = arr[s + i];
        leftSubArray.push_back(arr[s + i]);
    }
    for (int i = 0; i < l2; i++)
    {
        // rightSubArray[i] = arr[mid + i + 1];
        rightSubArray.push_back(arr[mid + i + 1]);
        
    }

    int indexOfLeftSubArray = 0;
    int indexOfRightSubArray = 0;

    while (indexOfLeftSubArray < l1 && indexOfRightSubArray < l2)
    {
        if (leftSubArray[indexOfLeftSubArray] <= rightSubArray[indexOfRightSubArray])
        {
            arr[indexOfMainArray] = leftSubArray[indexOfLeftSubArray];
            indexOfLeftSubArray++;
        }
        else
        {
            arr[indexOfMainArray] = rightSubArray[indexOfRightSubArray];
            indexOfRightSubArray++;
        }
        indexOfMainArray++;
    }

    while (indexOfLeftSubArray < l1)
    {
        arr[indexOfMainArray] = leftSubArray[indexOfLeftSubArray];
        indexOfMainArray++;
        indexOfLeftSubArray++;
    }
    while (indexOfRightSubArray < l2)
    {
        arr[indexOfMainArray] = rightSubArray[indexOfRightSubArray];
        indexOfMainArray++;
        indexOfRightSubArray++;
    }
    //     for(auto i: leftSubArray){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    //
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, mid, e);
}
int main()
{
    vector<int> arr = {34, 21, 7, 78, 23, 2, 22, 123, 45};
    int n = arr.size();
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}