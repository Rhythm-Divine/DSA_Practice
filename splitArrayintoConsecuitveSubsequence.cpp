#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> m, mx;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto i : nums)
    {
        if (m[i] == 0)
            continue;
        m[i]--;
        if (mx[i - 1] > 0)
        {
            mx[i - 1]--;
            mx[i]++;
        }
        else if (m[i + 1] != 0 && m[i + 2] != 0)
        {
            m[i + 1]--;
            m[i + 2]--;
            mx[i + 2]++;
        }
        else
            flag = false;
    }
    return flag;
}

int main()
{
    vector<int> x = {1, 2, 3, 4, 4, 5};
    bool ans = isPossible(x);
    cout << ans << endl;
}
