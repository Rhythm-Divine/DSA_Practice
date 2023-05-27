#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{

    int currMax = nums.at(0);
    int currMin = nums.at(0);
    int ans = nums.at(0);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            swap(currMax, currMin);
        }
        currMax = max(currMax * nums[i], nums[i]);
        currMin = min(currMin * nums[i], nums[i]);
        ans = max(ans, currMax);
    }
    return ans;
}
int main()
{
    vector<int> x = {-3, -3, 3, -4};
    int ans = maxProduct(x);
    cout << ans << endl;
}