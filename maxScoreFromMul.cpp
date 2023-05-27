#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int solve(int idx, vector<int> &nums, vector<int> &multipliers, int s, int e)
{
    if (idx == nums.size())
    {
        return 0;
    }
    if (dp[idx][s] != INT_MIN)
    {
        return dp[idx][s];
    }
    return dp[idx][s] = max(multipliers[idx] * nums[s] + solve(idx + 1, nums, multipliers, s + 1, e), multipliers[idx] * nums[e] + solve(idx + 1, nums, multipliers, s, e - 1));
}
int maximumScore(vector<int> &nums, vector<int> &multipliers)
{
    dp.assign(301, vector<int>(301, INT_MIN));
    return solve(0, nums, multipliers, 0, nums.size() - 1);
}
int main()
{
    vector<int> nums={-5,-3,-3,-2,7,1};
    vector<int> multipliers={-10,-5,3,4,6};
    cout<<maximumScore(nums,multipliers)<<endl;

}