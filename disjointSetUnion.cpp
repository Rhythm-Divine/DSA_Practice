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
        {
            return;
        }
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
        {
            return;
        }
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
int findCircleNum(vector<vector<int>> &isConnected)
{
    int size = isConnected.size();
    DSU dsu(size);

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; i <= size; j++)
        {
            if (i != j && isConnected[i][j] == 1)
            {
                dsu.unionByRank(i, j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= size; i++)
    {
        if (dsu.findPar(i) == i)
        {
            count++;
        }
    }
    return count;
}
int main()
{ // Test Case 1 - Basic Union
    cout << "Test Case 1 - Basic Union:" << endl;
    DSU dsu1(5);
    dsu1.unionBySize(1, 2);
    for (int i = 1; i <= 5; i++)
    {
        cout << "Parent of " << i << ": " << dsu1.par[i] << ", Size of Set: " << dsu1.size[i] << endl;
    }
    cout << endl;

    // Test Case 2 - Union with Existing Parent
    cout << "Test Case 2 - Union with Existing Parent:" << endl;
    DSU dsu2(5);
    dsu2.unionBySize(1, 2);
    dsu2.unionBySize(3, 4);
    dsu2.unionBySize(1, 3);
    for (int i = 1; i <= 5; i++)
    {
        cout << "Parent of " << i << ": " << dsu2.par[i] << ", Size of Set: " << dsu2.size[i] << endl;
    }
    cout << endl;

    // Test Case 3 - Union with Larger Set
    cout << "Test Case 3 - Union with Larger Set:" << endl;
    DSU dsu3(5);
    dsu3.unionBySize(1, 2);
    dsu3.unionBySize(1, 3);
    dsu3.unionBySize(4, 5);
    dsu3.unionBySize(3, 4);
    for (int i = 1; i <= 5; i++)
    {
        cout << "Parent of " << i << ": " << dsu3.par[i] << ", Size of Set: " << dsu3.size[i] << endl;
    }
    cout << endl;

    return 0;
    vector<vector<int>> v = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(v) << endl;
}
