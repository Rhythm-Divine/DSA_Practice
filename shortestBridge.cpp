#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int flag, std::vector<std::vector<int>>& grid, int& ans, int& cnt)
{
    grid[i][j] = -1;
    int n = grid.size();

    for (int cr = -1; cr <= 1; cr++)
    {
        for (int cc = -1; cc <= 1; cc++)
        {
            if (abs(cr) != abs(cc))
            {
                int newr = i + cr;
                int newc = j + cc;

                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] != flag)
                {
                    if (grid[newr][newc] == 0)
                    {
                        flag = !flag;
                        cnt++;
                        dfs(newr, newc, flag, grid, ans, cnt);
                    }
                    else
                    {
                        if (flag)
                        {
                            ans = std::min(ans, cnt);
                        }
                        else
                        {
                            dfs(newr, newc, flag, grid, ans, cnt);
                        }
                    }
                }
            }
        }
    }
}

int shortestBridge(std::vector<std::vector<int>>& grid)
{
    int n = grid.size();
    int cnt = 0;
    int ans = n * n;  // Initialize ans with a large enough value
    bool foundFirstIsland = false;

    for (int i = 0; i < n; i++)
    {
        if (foundFirstIsland)
            break;
        
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, 0, grid, ans, cnt);
                foundFirstIsland = true;
                break;
            }
        }
    }

    if (ans == n * n)
        return 0;  // Return 0 if the two islands are not connected

    return ans;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    cout << shortestBridge(v) << endl;
}