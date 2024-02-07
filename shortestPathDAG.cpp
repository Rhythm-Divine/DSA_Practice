#include <bits/stdc++.h>
using namespace std;


vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    unordered_map<int, vector<pair<int, int>>> m;
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    for (auto i : edges)
    {
        m[i[0]].push_back({i[1], i[2]});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();
        
        for(auto i:m[node]){
            int adjNode=i.first;
            int adjWt=i.second;
            if(dist[node]+adjWt<dist[adjNode]){
                dist[adjNode]=dist[node]+adjWt;
                pq.push({dist[adjNode],adjNode});
            }
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