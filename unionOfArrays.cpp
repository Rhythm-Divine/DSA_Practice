#include <bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)
{
    int count;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ans.push_back(b[i]);
    }
    sort(ans.begin(), ans.end());

    vector<int>::iterator itr;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == ans[i + 1])
        {
            ans.erase(ans.begin() + i);
        }
    }

    return ans.size();
}

int main()
{
    int x[6] = {1, 2, 2, 3, 4, 5};
    int y[3] = {3, 4, 5};
    int ans = doUnion(x, 6, y, 3);
    cout << ans << endl;
}