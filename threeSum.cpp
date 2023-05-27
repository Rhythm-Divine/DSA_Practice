#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    int target;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (n < 3 || nums[0] > 0)
    {
        return {};
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || nums[i] != nums[i - 1])
        {
            target = 0 - nums[i];
        }
        else
        {
            continue;
        }

        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                ans.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1])
                {
                    l++;
                }
                while (l < r && nums[r] == nums[r - 1])
                {
                    r--;
                }
                l++;
                r--;
            }
            else if (nums[l] + nums[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> x = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(x);
    for (auto i : ans)
    {
       for(auto j:i){
        cout<<j<<",";
       }
     
    }
}