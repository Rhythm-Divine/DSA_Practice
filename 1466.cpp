#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;
void make(unordered_map<int, vector<int>> &m, vector<vector<int>> &connections)
{
    for (auto i : connections)
    {
        m[i[0]].push_back(i[1]);
        m[i[1]].push_back(i[0]);
        s.insert({i[0], i[1]});
    }
}

int minReorder(int n, vector<vector<int>> &connections)
{
    unordered_map<int, vector<int>> m;
    vector<int> vis(n + 1, 0);
    s.clear();
    make(m, connections);
    queue<int> q;
    q.push(0);
    
    int ans = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (!vis[curr])
        {
            vis[curr] = 1;
            for (auto i : m[curr])
            {
                q.push(i);
                if (!vis[i] && s.count({curr, i}))
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> vec={{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout<<minReorder(6,vec)<<endl;
}