#include <bits/stdc++.h>
using namespace std;

/// @brief
/// @param heights
/// @return
int minimumEffortPath(vector<vector<int>> &heights)
{
    // using dijkstra
    int n = heights.size();
    int m = heights[0].size();
    //{abs diff,{row,col}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    q.push({heights[0][0], {0, 0}});

    while (!q.empty())
    {
        auto pair = q.top();
        int h = pair.first;
        int row = pair.second.first;
        int col = pair.second.second;

        q.pop();
        if (row == n - 1 && col == m - 1)
        {
            return h;
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (abs(i) != abs(j))
                {
                    int cr = row + i;
                    int cc = col + j;
                    if (cr >= 0 && cr < n && cc >= 0 && cc < m)
                    {
                        if (dist[cr][cc] < abs(heights[row][col] - heights[cr][cc]))
                        {
                            dist[cr][cc] = abs(heights[row][col] - heights[cr][cc]);
                            q.push({dist[cr][cc], {cr, cc}});
                        }
                    }
                }
            }
        }
    }
    return -1;
}
