#include <bits/stdc++.h>
using namespace std;

double new21Game(int n, int k, int maxPts)
{
    if (k == 0 || n >= k + maxPts)
    {
        return 1;
    }
    vector<double> dp(n + 1, 0);
    dp[0] = 1;

    double currSum = dp[0];

    double ans = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = currSum / maxPts;
        double dpi=dp[i];
        if (i < k)
        {
            currSum += dp[i];
        }
        else
        {
            ans += dp[i];
        }

        if (i - maxPts >= 0)
        {
            currSum -= dp[i - maxPts];
        }
    }
    return ans;
}

int main()
{
    cout<<new21Game(21,17,10)<<endl;
}