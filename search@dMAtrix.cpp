#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    bool flag;
    for(auto i:matrix){
        flag=  binary_search(i.begin(), i.end(), target);
        if(flag==true){
            return flag;
        }
    }
     
    return flag;
}
int main()
{

    vector<vector<int>> x = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool ans = searchMatrix(x, 34);
    cout << boolalpha << ans << endl;
}