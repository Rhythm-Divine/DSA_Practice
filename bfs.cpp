#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void makeG(map<int, vector<int>> &graph, vector<vector<int>> &g)
{
    for (auto i : g)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    for(auto j:graph){
        cout<<j.first;
        for(auto x:j.second){
            cout<<"->"<<x<<" ";
        }
        cout<<endl;
    }
}
vector<int> bfs(int n, vector<vector<int>> &g)
{
    unordered_map<int, vector<int>> graph;
    makeG(graph, g);

    queue<int> q;
    vector<int> vis(n + 1, -1);
    map<int,int> level;
    q.push(0);
    level[0]=0;
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        v.push_back(node);
        vis[node] = 1;
        for (int i : graph[node])
        {

            if (vis[i] == -1)
            {   
                
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    for(auto i:level){
        cout<<i.first<<"->"<<i.second<<endl;
    }

    return v;
}
int main()
{
    vector<vector<int>> g = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
    vector<int> ans = bfs(7, g);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}