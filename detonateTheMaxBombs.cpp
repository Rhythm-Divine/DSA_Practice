#include <bits/stdc++.h>
using namespace std;

int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        long long int x = bombs[i][0];
        long long int y = bombs[i][1];
        long long int r = bombs[i][2];

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                long long int x1 = bombs[j][0];
                long long int y1 = bombs[j][1];
                long long int r1 = bombs[j][2];

                if ((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r * r)
                {
                    m[i].push_back(j);
                }
            }
        }
    }
    vector<int> vis(n, 0);
    deque<int> q;
    int cnt = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        q.push_front(i);
        vis[i] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop_front();

            for (auto j : m[node])
            {
                if (vis[j] == 0)
                {
                    q.push_front(j);
                    vis[j] = 1;
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
        q.clear();
        cnt = 1;
        vis.clear();
        vis.resize(n, 0);
    }
    return ans;
}
int main()
{
    vector<vector<int>> v = {{2, 1, 3}, {6, 1, 4}};
    cout << maximumDetonation(v) << endl;
}