// #include <bits/stdc++.h>
// using namespace std;
// int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
// {
//     vector<int> dist(n, INT16_MAX);
//     unordered_map<int, pair<int, int>> m;
//     vector<pair<int, int>> graph[n];
//     for (auto i : flights)
//     {
//         graph[i[0]].push_back({i[1], i[2]});
//     }

//     m.insert({0, {src, 0}});
//     dist[src] = 0;
//     while (!m.empty())
//     {
//         auto it = m.begin();
//         int stops = it->first;
//         int node = it->second.first;
//         int dis = it->second.second;
//         cout << "stops : " << stops << " node : " << node << " dis : " << dis << endl;
//         m.erase(m.begin());
//         if (stops > k + 1 || stops > dist[node])
//         {
//             continue;
//         }

//         for (auto i : graph[node])
//         {
//             int neigNode = i.first;
//             int cost = i.second;

//             if (dis + cost < dist[neigNode] && stops <= k)
//             {
//                 dist[neigNode] = dis + cost;
//                 m.insert({stops + 1, {neigNode, dis + cost}});
//             }
//         }
//     }
//     return dist[dst] == INT16_MAX ? -1 : dist[dst];
// }
#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> dist(n, INT16_MAX);
    queue<pair<int, pair<int, int>>> pq;
    vector<pair<int, int>> graph[n];
    for (auto i : flights)
    {
        graph[i[0]].push_back({i[1], i[2]});
    }

    pq.push({0, {src, 0}});
    dist[src] = 0;
    while (!pq.empty())
    {
        auto p = pq.front();
        pq.pop();
        int dis = p.second.second;
        int node = p.second.first;
        int stops = p.first;
        if (stops > k)
        {
            continue;
        }

        for (auto i : graph[node])
        {
            int neigNode = i.first;
            int cost = i.second;
            if (dis + cost < dist[neigNode] && stops <= k)
            {
                dist[neigNode] = dis + cost;
                pq.push({stops + 1, {neigNode, dis+cost}});
            }
        }
    }
    return dist[dst] == INT16_MAX ? -1 : dist[dst];
}

int main()
{
    vector<vector<int>> x = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    int ans = findCheapestPrice(5, x, 0, 2, 2);
    cout << ans << endl;
}