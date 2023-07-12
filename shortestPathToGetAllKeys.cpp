#include <bits/stdc++.h>
using namespace std;

int shortestPathAllKeys(vector<string> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;
    int sr, sc;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (islower(grid[i][j]))
            {
                count++;
            }
            if (grid[i][j] == '@')
            {
                sr = i;
                sc = j;
            }
        }
    }
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<pair<int, int>,int>> q;
    q.push({{sr, sc},0});
    vis[sr][sc] = 1;
    unordered_set<char> s;
    while (!q.empty())
    {
        auto r = q.front().first.first;
        auto c = q.front().first.second;
        auto moves=q.front().second;
        auto kya = grid[r][c];
        q.pop();
        for (int cr = -1; cr <= 1; cr++)
        {
            for (int cc = -1; cc <= 1; cc++)
            {
                if (abs(cr) != abs(cc))
                {
                    int newr = r + cr;
                    int newc = c + cc;
                    
                    if (newr >= 0 && newr < m && newc >= 0 && newc < n && grid[newr][newc] != '#' && vis[newr][newc] == 0)
                    {
                        if (isupper(grid[newr][newc]))
                        {
                            if (!s.count(tolower(grid[newr][newc])))
                            {
                                // q.push({newr,newc});
                                // vis[newr][newc]=1;
                                break;
                            }
                        }
                        else if (islower(grid[newr][newc]))
                        {
                            s.insert(grid[newr][newc]);
                        }
                        q.push({{newr, newc},moves+1});
                        vis[newr][newc] = 1;
                        if (s.size() == count)
                        {
                            return moves+1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    vector<string> v = {"@...a",".###A","b.BCc"};
    cout << shortestPathAllKeys(v) << endl;
}