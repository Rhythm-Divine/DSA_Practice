#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
    {
        return -1;
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    grid[0][0] = 2;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int r = node.first.first;
        int c = node.first.second;
        int step = node.second;

        if (r == n - 1 && c == n - 1)
        {
            return step;
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                int newr = r + i;
                int newc = c + j;
                if (newr < n && newr >= 0 && newc < n && newc >= 0 && grid[newr][newc] == 0)
                {
                    q.push({{newr, newc}, step + 1});
                    grid[newr][newc] = 2;
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> v = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << shortestPathBinaryMatrix(v) << endl;
}