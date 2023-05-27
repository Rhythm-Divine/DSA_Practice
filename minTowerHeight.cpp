#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    for (int i = 0; i < (n / 2)-1; i++)
    {

        arr[i] = arr[i] + k;
    }
    for (int i = n / 2; i < n; i++)
    {
        if (arr[i] > k)
        {
            arr[i] = arr[i] - k;
        }
        else
        {
            arr[i] = arr[i] + k;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr+n/2,arr+n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int ans = arr[n - 1] - arr[0];
    return ans;
}

int main()
{
    int arr[10] = {2 ,6, 3, 4, 7, 2, 10, 3, 2, 1};
    int ans = getMinDiff(arr, 10, 5);
    cout << ans << endl;
}