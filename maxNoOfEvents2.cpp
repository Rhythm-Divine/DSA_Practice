#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int bs(int s, int e, int tar, vector<vector<int>> &events)
{
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (events[mid][1] == tar)
        {
            return mid;
        }
        else if (events[mid][1] < tar)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}
int dp(int i, int k, vector<vector<int>> &events)
{
    int n = events.size();
    if (i == n)
    {
        return 0;
    }
    if (k == 0)
    {
        return 0;
    }

    ans = dp(i + 1, k, events);
    int newi = bs(i, n, events[i][1] + 1, events);
    if (newi != -1)
    {
        ans = max(ans, events[i][2] + dp(newi, k - 1, events));
    }

    return ans;
}
int maxValue(vector<vector<int>> &events, int k)
{
    int n = events.size();
    sort(events.begin(), events.end());
    return dp(0, k, events);
}
int main()
{
    vector<vector<int>> x = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    cout << maxValue(x, 2) << endl;
}