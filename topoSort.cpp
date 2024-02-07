#include<bits/stdc++.h>
using namespace std;

vector<int> topo(vector<vector<int>> &g){
    unordered_map<int,vector<int>> graph;
    vector<int> indegree(g.size()+1,0);
    vector<int> ans;
    queue<int> q;
    for(auto i:g){
        graph[i[0]].push_back(i[1]);
        indegree[i[1]]++;
    }

    for(int i=0;i<g.size()+1;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();

        for(auto i:graph[node]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> g = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
    vector<int> ans = topo(g);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}