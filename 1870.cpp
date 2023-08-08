#include <bits/stdc++.h>
using namespace std;

bool solve(int mid, vector<int> &dist, double hour)
{
    int n = dist.size();
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        float temp = float(dist[i]) / mid;
        ans = ans + ceil(temp);
    }
    ans += float(dist[n - 1]) / mid;
    if (ans <= hour)
    {
        return true;
    }
    return false;
}
int minSpeedOnTime(vector<int> &dist, double hour)
{
    int n = dist.size();
    int l = 0;
    int h = 1e7;
    int res = -1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (solve(mid, dist, hour))
        {
            res = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> v = {1, 9};
    cout << minSpeedOnTime(v, 1.18) << endl;
}