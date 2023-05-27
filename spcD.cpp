#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count = 0;
    long long int n;
    cin >> n;
    long long int temp;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    int j = 0;
    sort(arr.begin(), arr.end());
    //  for(auto i:arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= 2 * arr[j])
        {
            count++;
            j++;
        }
        else
        {
            continue;
        }
    }
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int res = n - count;
    cout << res << endl;
}