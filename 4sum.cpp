#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums)
{
    int n = nums.size();
    int target;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (n < 4 || nums[0] > 0)
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
        int m = i + 2;
        int r = n - 1;

        while (l < m && m < r)
        {
            if (nums[l] + nums[r] + nums[m] == target)
            {
                ans.push_back({nums[i], nums[l], nums[r], nums[m]});
                while (l < m && m < r && nums[l] == nums[l + 1])
                {
                    l++;
                }
                while (l < m && m < r && nums[m] == nums[m + 1])
                {
                    m++;
                }
                while (l < m && m < r && nums[r] == nums[r - 1])
                {
                    r--;
                }
                l++;
                r--;
                m++;
            }
            else if (nums[l] + nums[r] + nums[m] < target)
            {
                if (m < r)
                {
                    m++;
                    
                }
                else if(m=r-1 && l<m)
                {
                    l++;
                }
                else{
                    l++;
                }
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
    vector<int> x = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = fourSum(x);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << ",";
        }
    }
}