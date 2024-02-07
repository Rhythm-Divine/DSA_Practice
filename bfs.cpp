#include <bits/stdc++.h>
using namespace std;
vector<int> v;
// void makeG(unordered_map<int, vector<int>> &graph, vector<vector<int>> &g)
// {
//     for (auto i : g)
//     {
//         graph[i[0]].push_back(i[1]);
//         graph[i[1]].push_back(i[0]);
//     }
//     for(auto j:graph){
//         cout<<j.first;
//         for(auto x:j.second){
//             cout<<"->"<<x<<" ";
//         }
//         cout<<endl;
//     }
// }
vector<int> bfs(int n, vector<vector<int>> &g)
{
    unordered_map<int,vector<int>> graph;
    for(auto i:g){
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    vector<int> ans;
    queue<int> q;
    vector<int> vis(n,-1);

    vis[0]=1;
    q.push(0);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto i:graph[node]){
            if(vis[i]==-1){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    return ans;
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