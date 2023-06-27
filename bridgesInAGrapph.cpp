#include <bits/stdc++.h>
using namespace std;



void dfs(int node, int par, vector<int> &id, vector<int> &low,
         vector<int> &vis, unordered_map<int, vector<int>> &m,
         vector<vector<int>> &ans,int &count)
{
    vis[node] = 1;
    id[node] = count;
    low[node] = count;
    count++;
    for (auto i : m[node])
    {
        if (i == par)
        {
            continue;
        }
        if (!vis[i])
        {
            dfs(i, node, id, low, vis, m, ans,count);
            low[node] = min(low[node], low[i]);
            cout<<low[i]<<" "<< id[node]<<endl;
            if (low[i] > id[node])
            {
                ans.push_back({node, i});
            }
        }
        else
        {
            low[node] = min(low[node], low[i]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, vector<int>> m;

    for (auto i : connections)
    {
        m[i[0]].push_back(i[1]);
        m[i[1]].push_back(i[0]);
    }

    vector<int> id(n, 0);
    vector<int> low(n, 0);
    vector<int> vis(n, 0);
    int count=0;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, id, low, vis, m, ans,count);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> v={{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> temp=criticalConnections(4,v);

    for(auto i:temp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}