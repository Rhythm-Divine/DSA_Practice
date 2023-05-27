#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
   
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            
            break;
        }

        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        else
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
}
int main()
{
    vector<int> x = {3, 2, 1};
    nextPermutation(x);
    for (auto i : x)
    {
        cout << i << " ";
    }
}