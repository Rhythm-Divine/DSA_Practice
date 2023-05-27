#include <bits/stdc++.h>
using namespace std;
vector<int> vis(7,-1);
map<int, vector<int>> graph;
vector<int> ans;
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

void dfs(int sNode){
    vis[sNode]=1;
    ans.push_back(sNode);
    for(auto i:graph[sNode]){
        if(vis[i]==-1){
            dfs(i);
        }
    }
}
int main()
{
    vector<vector<int>> g = {{0, 1}, {0, 2}, {0, 4}, {4, 3}};
    makeG(graph,g);
    dfs(0);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}