#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int s, int mid, int e, int &invCount)
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
            invCount += l1 - indexOfLeftSubArray;
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
    cout<<s<<" "<<mid<<" "<<e<<" "<<invCount<<"abc"<<endl;
     for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
// }
}

void mergeSort(vector<int> &arr, int s, int e, int &invCount)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid, invCount);
    mergeSort(arr, mid + 1, e, invCount);
 
    merge(arr, s, mid, e, invCount);
       
}
int main()
{
    vector<int> arr = {5,4,3,2,9};
    int n = arr.size();
    int invCount = 0;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1, invCount);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << invCount << endl;
}