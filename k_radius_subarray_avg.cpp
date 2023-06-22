#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int> &nums, int k)
{
    int n = nums.size();
    if (2 * n + 1 < k)
    {
        vector<int> v(n, -1);
        return v;
    }
    vector<int> ans(n, 0);
    long long int curr = 0;
    int cnt = 2 * k + 1;
    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        if (i - k < 0)
        {
            ans[i] = -1;
            continue;
        }
        if (i >= cnt - 1)
        {
            ans[i - k] = floor(int(curr / cnt));
            curr -= nums[i - 2 * k];
        }
        if (i >= n - k)
        {
            ans[i] = -1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    vector<int> x = getAverages(v, 3);
    for (auto i : x)
    {
        cout << i << " ";
    }
}