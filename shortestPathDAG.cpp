#include <bits/stdc++.h>
using namespace std;

void dfs(int i, unordered_map<int, vector<pair<int, int>>> &m, vector<int> &vis, stack<int> &st)
{
    vis[i] = 1;

    for (auto node : m[i])
    {
        if (vis[node.first] == 0)
        {
            dfs(node.first, m, vis, st);
        }
    }
    st.push(i);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    unordered_map<int, vector<pair<int, int>>> m;
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    for (auto i : edges)
    {
        m[i[0]].push_back({i[1], i[2]});
    }

    vector<int> vis(N, 0);
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, m, vis, st);
        }
    }

    while (!st.empty())
    {
        int i = st.top();
        st.pop();

        for (auto node : m[i])
        {
            if (dist[i] + node.second < dist[node.first])
            {
                dist[node.first] = dist[i] + node.second;
            }
        }
    }
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> v={{0,1,2},{2,1,2},{2,4,2},{1,4,8},{1,3,6}};
    vector<int> ans=shortestPath(5,5,v);

    for(auto i:ans){
        cout<<i<<" ";
    }
}