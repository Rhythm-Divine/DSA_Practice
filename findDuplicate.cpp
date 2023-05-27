#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
        {
            break;
        }
    }
    int intersection = nums[0];
    while (slow != intersection)
    {

        slow = nums[slow];
        intersection = nums[intersection];
    }
    return slow;
}
int main()
{
    vector<int> x = {2,1,4,6,3,7,2};
    int ans = findDuplicate(x);
    cout << ans;
}