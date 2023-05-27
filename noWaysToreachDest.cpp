#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    long long int mod = 1e9 + 7;
    unordered_map<int, vector<pair<int, int>>> m;
    //{src--> {time,dest}}
    for (auto i : roads)
    {
        m[i[0]].push_back({i[2], i[1]});
        m[i[1]].push_back({i[2], i[0]});
    }

    // for (auto i : m)
    // {
    //     cout << i.first << " -->";
    //     for (auto j : i.second)
    //     {
    //         cout << j.first << "-" << j.second << " , ";
    //     }
    //     cout << endl;
    // }
    vector<long long int> dist(n, 1e12);
    vector<int> ways(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    dist[0] = 0;
    ways[0] = 1;

    while (!q.empty())
    {
        auto pair = q.top();
        int time = pair.first;
        int node = pair.second;
        q.pop();
        for (auto i : m[node])
        {
            int t = i.first;
            int nd = i.second;

            if (dist[nd] > time + t)
            {
                dist[nd] = time + t;
                q.push({dist[node]+t, nd});
                ways[nd] = ways[node];
            }
            else if (dist[nd] == time + t)
            {
                ways[nd] = (ways[nd] + ways[node]) % mod;
            }
        }
    }
    return (ways[n - 1]) % mod;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 1}, {1, 2, 4}, {0, 4, 3}, {3, 2, 5}, {3, 4, 1}, {3, 0, 5}, {1, 3, 1}};
    cout << countPaths(5, v) << endl;
}