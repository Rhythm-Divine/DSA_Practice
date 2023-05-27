#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();

    int x, y, z;
    int ans;
    int diff = INT16_MAX;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {

        x = nums[i];
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            z = nums[l] + nums[r] + x;
            y = abs(target - (z));
            if (z == target)
            {
                ans = target;
                // while (l < r && nums[l] == nums[l + 1])
                // {
                //     l++;
                // }
                // while (l < r && nums[r] == nums[r - 1])
                // {
                //     r--;
                // }
                // l++;
                // r--;
                return ans;
            }
            if (y < diff)
            {
                diff = y;
                ans = z;
            }
            if (z > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> x = {-1,2,1,-4};
    int ans = threeSumClosest(x, 1);
    cout << ans << endl;
}