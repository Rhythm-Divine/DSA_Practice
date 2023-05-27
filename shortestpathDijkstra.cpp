#include <bits/stdc++.h>
using namespace std;

void createPath(vector<int> &ans, vector<int> &par, int n)
{
    while (par[n] != n)
    {
        ans.push_back(n);
        n = par[n];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
}
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    set<pair<int, int>> s;
    vector<vector<pair<int,int>>> mp(n+1,vector<pair<int,int>>());
    for (auto i : edges)
    {
        mp[i[0]].push_back({i[2], i[1]});
        mp[i[1]].push_back({i[2], i[0]});
    }
    
    
    vector<int> ans;
    vector<int> dist(n+1, INT_MAX);
    vector<int> par(n+1, 0);
    for (int i = 1; i < n; i++)
    {
        par[i] = i ;
    }

    dist[1] = 0;
    s.insert({0, 1});

    while (!s.empty())
    {
        auto p = *(s.begin());
        int d = p.first;
        int node = p.second;

        s.erase(p);
        for (auto i : mp[node])
        {
            auto n = i.second;
            auto nd = i.first;

            if (dist[n] > dist[node] + nd)
            {
                if (dist[n] != INT_MAX)
                {
                    s.erase({dist[n], n});
                }
                dist[n] = dist[node] + nd;
                s.insert({dist[n], n});
                par[n] = node;
            }
        }
    }
    createPath(ans, par, n);
    return ans;
}
int main()
{
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    vector<int> x = shortestPath(5, 6, edges);
    for (auto i : x)
    {
        cout << i << " ";
    }
}