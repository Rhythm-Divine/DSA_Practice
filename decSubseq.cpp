#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vec;
set<vector<int>> ans;
vector<int> temp;
void solve(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        if (temp.size() >= 2)
        {
            ans.insert(temp);
        }
        return;
    }
    if (temp.size() == 0 || temp.back() <= nums[idx])
    {
        temp.push_back(nums[idx]);
        solve(nums, idx + 1);
        temp.pop_back();
    }
    solve(nums, idx + 1);
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    solve(nums, 0);
    vec.assign(ans.begin(), ans.end());
    return vec;
}
int main()
{
    vector<int> x = {4, 4, 6, 7};
    vector<vector<int>> an = findSubsequences(x);
    for (auto i : an)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}