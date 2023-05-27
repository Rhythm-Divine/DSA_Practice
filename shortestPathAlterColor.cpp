#include <bits/stdc++.h>
using namespace std;


void adjMat(vector<vector<int>> &g, int n, vector<vector<int>> &red, vector<vector<int>> &blue)
{
    if (red.size() > 0)
    {
        for (vector<int> i : red)
        {
            g[i[0]][i[1]] = 1;
        }
    }
    if (blue.size() > 0)
    {
        for (vector<int> i : blue)
        {
            if (g[i[0]][i[1]] == 1)
            {
                g[i[0]][i[1]] = 0;
            }
            else
            {
                g[i[0]][i[1]] = -1;
            }
        }
    }
}

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    vector<vector<int>> g(n, vector<int>(n, -101));
    adjMat(g, n, redEdges, blueEdges);
    queue<vector<int>> q;
    q.push({0, 1});
    q.push({0, -1});
    vector<int> ans(n, INT_MAX);
    ans[0] = 0;
    // visited
    set<vector<int>> visited;
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            vector<int> curr = q.front();
            q.pop();
            int node = curr[0];
            int color = curr[1];
            int oppColor = -color;
            if (visited.count({node, color}))
            {
                continue;
            }
            visited.insert({node, color});
            for (int j = 0; j < n; j++)
            {
                if (g[node][j] == oppColor|| g[node][j]==0)
                {
                    if (!visited.count({j, oppColor}))
                    {
                        q.push({j, oppColor});
                        ans[j] = min(ans[j], level + 1);
                    }
                }
            }
        }
        level++;
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == INT_MAX)
        {
            ans[i] = -1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> red = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> blue = {{1,2},{2,3},{3,1}};

    vector<int> res = shortestAlternatingPaths(5, red, blue);

    for (auto i : res)
    {
        cout << i << " ";
    }
}