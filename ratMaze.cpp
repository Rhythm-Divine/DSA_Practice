#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<string> ans;
    string temp = "";
    void solve(int i, int j, vector<vector<int>> &m, int n, string temp, vector<vector<bool>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(temp);
            return;
        }

        if (i + 1 < n && vis[i + 1][j] == false && m[i + 1][j] == 1)
        {
            vis[i][j] = true;
            solve(i + 1, j, m, n, temp + "D", vis);
            vis[i][j] = false;
        }

        if (i - 1 >= 0 && vis[i - 1][j] == false && m[i - 1][j] == 1)
        {
            vis[i][j] = true;
            solve(i - 1, j, m, n, temp + "U", vis);
            vis[i][j] = false;
        }

        if (j + 1 < n && vis[i][j + 1] == false && m[i][j + 1] == 1)
        {
            vis[i][j] = true;
            solve(i, j + 1, m, n, temp + "R", vis);
            vis[i][j] = false;
        }

        if (j - 1 >= 0 && vis[i][j - 1] == false && m[i][j - 1] == 1)
        {
            vis[i][j] = true;
            solve(i, j - 1, m, n, temp + "L", vis);
            vis[i][j] = false;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<bool> x(n, false);
        vector<vector<bool>> vis(n, x);

        if (m[0][0] == 1)
        {
            solve(0, 0, m, n, temp, vis);
        }
        return ans;
    }
};
int main()
{
    int n = 4;

    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    Solution obj;
    vector<string> result = obj.findPath(m, n);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;
}