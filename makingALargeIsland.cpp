#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> rank;
    vector<int> par;
    vector<int> size;
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        par.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int u)
    {
        if (u == par[u])
        {
            return u;
        }
        return par[u] = findPar(par[u]);
    }

    void unionByRank(int u, int v)
    {
        int up_u = findPar(u);
        int up_v = findPar(v);

        if (rank[up_u] < rank[up_v])
        {
            par[up_u] = up_v;
        }
        else if (rank[up_v] < rank[up_u])
        {
            par[up_v] = up_u;
        }
        else
        {
            par[up_v] = up_u;
            rank[up_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int up_u = findPar(u);
        int up_v = findPar(v);
        if (up_u == up_v)
            return;
        if (size[up_u] < size[up_v])
        {
            par[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            par[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        return;
    }
};

int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DSU dsu(n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int cell = i * n + j;
                for (int cr = -1; cr <= 1; cr++)
                {
                    for (int cc = -1; cc <= 1; cc++)
                    {
                        if (abs(cr) != abs(cc))
                        {
                            int newr = i + cr;
                            int newc = j + cc;
                            if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1)
                            {
                                int newcell = newr * n + newc;
                                dsu.unionBySize(cell, newcell);
                            }
                        }
                    }
                }
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                int cell = i * n + j;
                unordered_set<int> upars;
                for (int cr = -1; cr <= 1; cr++)
                {
                    for (int cc = -1; cc <= 1; cc++)
                    {
                        if (abs(cr) != abs(cc))
                        {
                            int newr = i + cr;
                            int newc = j + cc;
                            if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1)
                            {
                                int newcell = newr * n + newc;
                                upars.insert(dsu.findPar(newcell));
                            }
                        }
                    }
                }
                int ans = 0;
                for (auto it : upars)
                {
                    cout << it << " ";
                    ans += dsu.size[it];
                }
                mx = max(mx, ans + 1);
            }
        }
    }

    for(int i=0;i<n*n;i++){
        
    }
    return mx;
}

int main()
{
    vector<vector<int>> v = {{1, 1}, {1, 1}};
    cout << largestIsland(v) << endl;
}