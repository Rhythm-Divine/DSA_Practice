#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int low = INT16_MAX;
    int ans = 0;
    if (prices.size() <= 1)
    {
        return ans;
    }

    for (int i = 0; i < prices.size(); i++)
    {
        low = min(low, prices[i]);
        ans = max(ans, prices[i] - low);
    }
    return ans;
}

int main()
{
    vector<int> x = {7,1,5,3,6,4};
    int ans = maxProfit(x);
    cout << ans << endl;
}