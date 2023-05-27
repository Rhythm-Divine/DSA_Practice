#include <bits/stdc++.h>
using namespace std;

int dfs(int node, unordered_map<int, vector<int>> &m, set<int> &vis, set<int> &path, vector<vector<int>> &dp, string &colors)
{
    if (path.count(node))
    {
        return INT_MAX;
    }
    if (vis.count(node))
    {
        return 0;
    }

    vis.insert(node);
    path.insert(node);
    dp[node][colors[node] - 'a'];
    for (auto i : m[node])
    {
        if (dfs(i, m, vis, path, dp, colors) == INT_MAX)
        {
            return INT_MAX;
        }
        for (int clr = 0; clr < 26; clr++)
        {
                dp[node][clr]=max(dp[node][clr],(clr==colors[node]?1:0)+dp[i][clr]);
        }
    }
    path.erase(node);
    return *max_element(dp[node].begin(),dp[node].end());
}
int largestPathValue(string colors, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> m;
    for (auto i : edges)
    {
        m[i[0]].push_back(i[1]);
    }

    int n = colors.size();
    int ans = 0;
    set<int> vis;
    set<int> path;

    vector<vector<int>> dp(n, vector<int>(26, 0));

    for (int i = 0; i < n; i++)
    {
        ans = max(dfs(i, m, vis, path, dp, colors), ans);
    }
    return ans == INT_MAX ? -1 : ans;
}
int main()
{
}