#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void solve(int index, vector<int> &arr, vector<int> &toAdd)
{
    ans.push_back(toAdd);

   
    for (int i = index; i < arr.size(); i++)
    {
        if (i != index && arr[i] == arr[i - 1])
        {
            continue;
        }
        toAdd.push_back(arr[i]);
        solve(i + 1, arr, toAdd);
        toAdd.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> toAdd;
    sort(nums.begin(), nums.end());
    solve(0, nums, toAdd);
    return ans;
}
int main()
{
    vector<int> n = {1, 2, 2};

    vector<vector<int>> res = subsetsWithDup(n);
    for (auto i : res)
    {
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}