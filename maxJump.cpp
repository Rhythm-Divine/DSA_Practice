#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    int count = 0;
    int i=0;
   while(i<n)
    {
        if (arr[i] == 0)
        {
            return -1;
        }
        
        i += arr[i];
        count++;
        if (i >= n-1)
        {
            return count;
            break;
        }
    }
    return -1;
}

int main()
{
    int arr[11] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int ans = minJumps(arr, 11);
    cout << ans << endl;
}