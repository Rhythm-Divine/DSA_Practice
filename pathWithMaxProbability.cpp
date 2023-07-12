#include <bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{

    unordered_map<int, vector<pair<double, int>>> m;
    int x=0;
    for (auto i:edges)
    {
        m[i[0]].push_back({succProb[x],i[1]});
        m[i[1]].push_back({succProb[x],i[0]});
        // m[edges[i][0]].push_back({succProb[i], edges[i][1]});
        // m[edges[i][1]].push_back({succProb[i], edges[i][0]});
        x++;
    }

    vector<int> vis(n, 0);
    priority_queue<pair<double, int>, vector<pair<double, int>>> q;
    vector<double> prob(n, 1.0);
    q.push({1.0, start});

    while (!q.empty())
    {
        auto prb = q.top().first;
        auto node = q.top().second;
        vis[node]=1;
        q.pop();

        if (node == end)
        {
            return prb;
        }
        for (auto i : m[node])
        {
            if (!vis[i.second])
            {
                prob[i.second] = prb * i.first;
                cout << prob[i.second] << " " << i.second << endl;
                q.push({prob[i.second], i.second});
            }
        }
    }
    return 0;
}

int main()
{
    // n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
    vector<vector<int>> v = {{0, 1}};
    vector<double> p = {0.5};
    cout << fixed << setprecision(2) << maxProbability(3, v, p, 0, 2) << endl;
}