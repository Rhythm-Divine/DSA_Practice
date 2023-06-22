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

        if (up_u == up_v)
            return;
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


    int removeStones(vector<vector<int>> &stones)
    {
        int row = INT_MIN;
        int col = INT_MIN;
        for (auto i : stones)
        {
            row = max(row, i[0]);
            col = max(col, i[1]);
        }
        DSU dsu(row + col + 1);
        unordered_set<int> containStones;
        for (auto i : stones)
        {
            dsu.unionByRank(i[0], row + i[1] + 1);
        }
        
        int cnt = 0;
        for (auto i : containStones)
        {
            cout<<i<<" ";
            if (dsu.findPar(i) == i)
            {
                cnt++;
            }
        }
        return stones.size() - cnt;
    }

    int main()
    {
        vector<vector<int>> v={{0,0}};  
        cout<<removeStones(v)<<endl;
    }