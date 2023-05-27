#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &image, int color, int pcol)
{
    vis[r][c] = 1;
    image[r][c] = color;
    for (int cr = -1; cr <= 1; cr++)
    {
        for (int cc = -1; cc <= 1; cc++)
        {
            if (abs(cr) != abs(cc))
            {
                int nr = r + cr;
                int nc = c + cc;
                if (nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && vis[nr][nc] == 0 && image[nr][nc] == pcol)
                {
                    dfs(nr, nc, vis, image, color, pcol);
                }
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();
    int pcol = image[sr][sc];
    vector<vector<int>> vis(m, vector<int>(n, 0));
    dfs(sr, sc, vis, image, color, pcol);
    return image;
}

int main()
{
    vector<vector<int>> v = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> ans = floodFill(v, 1, 1, 2);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}